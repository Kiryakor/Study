//
//  DoctorsViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

enum StateData {
    case base
    case find
}

class DoctorsPresenter {
    var doctorSingelton = DoctorsSingelton.share
    var stateData:StateData = .base
    var findData:[PeopleModel] = []
}

class DoctorsController: UIViewController {
    
    @IBOutlet weak var tableView: UITableView!
    
    var presenter = DoctorsPresenter()
    
    override func viewWillAppear(_ animated: Bool) {
        tableView.reloadData()
    }
    
    override func viewDidLoad(){
        super.viewDidLoad()
        tableView.delegate = self
        tableView.dataSource = self
        tableView.register(BasicCell.self, forCellReuseIdentifier: Constant.Cell.cellId(.dostors)())
        tableView.tableFooterView = UIView()
        tableView.rowHeight = 80
    }
    
    @IBAction func searchDoctors(_ sender: UIBarButtonItem) {
        presenter.findData.removeAll()
        let searchAlert = UIAlertController(title: "Поиск", message: nil, preferredStyle: .alert)
        searchAlert.addTextField(configurationHandler: nil)
        searchAlert.addAction(UIAlertAction(title: "Поиск по профессии", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.presenter.doctorSingelton.data{
                if i.profession.contains(textField!.text!){
                    self.presenter.findData.append(i)
                }
            }
            self.presenter.stateData = .find
            self.tableView.reloadData()
        }))
        searchAlert.addAction(UIAlertAction(title: "Поиск по имени", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.presenter.doctorSingelton.data{
                if i.fullName.contains(textField!.text!){
                    self.presenter.findData.append(i)
                }
            }
            self.presenter.stateData = .find
            self.tableView.reloadData()
        }))
        searchAlert.addAction(UIAlertAction(title: "Показать всё", style: .cancel, handler: { [unowned self] (alert) in
            self.presenter.stateData = .base
            self.tableView.reloadData()
        }))
        self.present(searchAlert,animated: true)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "doctorId"{
            if let nextViewController = segue.destination as? AddNewPeopleController {
                nextViewController.presenter.stateAddPeople = .doctor
            }
        }
    }
}

extension DoctorsController: UITableViewDelegate, UITableViewDataSource{
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch presenter.stateData {
        case .find:
            return presenter.findData.count
        case .base:
            return presenter.doctorSingelton.data.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Constant.Cell.cellId(.dostors)(), for: indexPath) as! BasicCell
        switch presenter.stateData {
        case .base:
            cell.setValue(data: presenter.doctorSingelton.data[indexPath.row])
        case .find:
            cell.setValue(data: presenter.findData[indexPath.row])
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete, presenter.stateData == .base{
            presenter.doctorSingelton.data.remove(at: indexPath.row)
            tableView.reloadData()
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "detailVC") as! DetailDoctorsController
        vc.presenter.index = indexPath.row
        navigationController?.pushViewController(vc,animated: true)
    }
}

