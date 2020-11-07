//
//  WriteNewPatientController.swift
//  OOP
//
//  Created by Кирилл on 07.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class WriteNewPatientController: UIViewController {

    var patientSingelton = PatientSingelton.share
    var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView = UITableView()
        tableView.register(BasicCell.self, forCellReuseIdentifier: Constant.Cell.cellId(.addPatient)())
        tableView.delegate = self
        tableView.tableFooterView = UIView()
        tableView.dataSource = self
        view.addSubview(tableView)
        tableView.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            tableView.topAnchor.constraint(equalTo: view.topAnchor),
            tableView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            tableView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            tableView.bottomAnchor.constraint(equalTo: view.bottomAnchor)
        ])
    }
}

extension WriteNewPatientController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        patientSingelton.data.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: Constant.Cell.cellId(.addPatient)(), for: indexPath) as! BasicCell
        cell.setValue(data: patientSingelton.data[indexPath.row])
        return cell
    }
}
