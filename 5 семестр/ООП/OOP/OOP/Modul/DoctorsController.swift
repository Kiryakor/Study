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

class DoctorsController: UIViewController {
    
    var doctorSingelton = DoctorsSingelton.share
    var stateData:StateData = .base
    var findData:[PeopleModel] = []
    @IBOutlet weak var tableView: UITableView!
    
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
        findData.removeAll()
        let searchAlert = UIAlertController(title: "Поиск", message: nil, preferredStyle: .alert)
        searchAlert.addTextField(configurationHandler: nil)
        searchAlert.addAction(UIAlertAction(title: "Поиск по профессии", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.doctorSingelton.data{
                if i.profession.contains(textField!.text!){
                    self.findData.append(i)
                }
            }
            self.stateData = .find
            self.tableView.reloadData()
        }))
        searchAlert.addAction(UIAlertAction(title: "Поиск по имени", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.doctorSingelton.data{
                if i.fullName.contains(textField!.text!){
                    self.findData.append(i)
                }
            }
            self.stateData = .find
            self.tableView.reloadData()
        }))
        searchAlert.addAction(UIAlertAction(title: "Показать всё", style: .cancel, handler: { [unowned self] (alert) in
            self.stateData = .base
            self.tableView.reloadData()
        }))
        self.present(searchAlert,animated: true)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "doctorId"{
            if let nextViewController = segue.destination as? AddNewPeopleController {
                nextViewController.stateAddPeople = .doctor
            }
        }
    }
}

extension DoctorsController: UITableViewDelegate, UITableViewDataSource{
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch stateData {
        case .find:
            return findData.count
        case .base:
            return doctorSingelton.data.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Constant.Cell.cellId(.dostors)(), for: indexPath) as! BasicCell
        switch stateData {
        case .base:
            cell.setValue(data: doctorSingelton.data[indexPath.row])
        case .find:
            cell.setValue(data: findData[indexPath.row])
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete, stateData == .base{
            doctorSingelton.data.remove(at: indexPath.row)
            tableView.reloadData()
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "detailVC") as! DetailDoctorsController
        vc.index = indexPath.row
        navigationController?.pushViewController(vc,animated: true)
    }
}
