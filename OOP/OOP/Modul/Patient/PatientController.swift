//
//  ViewController.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class PatientController: UIViewController {

    var tableView: UITableView!{
        didSet{
            tableView.delegate = self
            tableView.dataSource = self
            tableView.register(BasicCell.self, forCellReuseIdentifier: Constant.Cell.cellId(.patient)())
            tableView.tableFooterView = UIView()
            tableView.rowHeight = 80
        }
    }
    
    var patientSingelton = PatientSingelton.share
    var stateData:StateData = .base
    var findData:[PeopleModel] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTable()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        tableView.reloadData()
    }
    
    @IBAction func searchPatient(_ sender: Any) {
        findData.removeAll()
        let searchAlert = UIAlertController(title: "Поиск", message: nil, preferredStyle: .alert)
        searchAlert.addTextField(configurationHandler: nil)
        searchAlert.addAction(UIAlertAction(title: "Поиск по профессии", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.patientSingelton.data{
                if i.profession.contains(textField!.text!){
                    self.findData.append(i)
                }
            }
            self.stateData = .find
            self.tableView.reloadData()
        }))
        searchAlert.addAction(UIAlertAction(title: "Поиск по имени", style: .default, handler: { [unowned self] (alert) in
            let textField = searchAlert.textFields!.first
            for i in self.patientSingelton.data{
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
        if segue.identifier == "patientId"{
            if let nextViewController = segue.destination as? AddNewPeopleController {
                nextViewController.stateAddPeople = .patient
            }
        }
    }
}

extension PatientController: UITableViewDelegate, UITableViewDataSource{
    
    func setupTable() {
        tableView = UITableView(frame: view.frame)
        view.addSubview(tableView)
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch stateData {
        case .base:
            return patientSingelton.data.count
        case .find:
            return findData.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Constant.Cell.cellId(.patient)(), for: indexPath) as! BasicCell
        switch stateData {
        case .base:
            cell.setValue(data: patientSingelton.data[indexPath.row])
        case .find:
            cell.setValue(data: findData[indexPath.row])
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete{
            patientSingelton.data.remove(at: indexPath.row)
            tableView.reloadData()
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "detailPacientVC") as! DetailPersonController
        navigationController?.pushViewController(vc,animated: true)
    }
}
