//
//  WritePatientToDoctorViewController.swift
//  OOP
//
//  Created by Кирилл on 10.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class WritePatientToDoctorViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!{
        didSet{
            tableView.rowHeight = 80
            tableView.tableFooterView = UIView()
        }
    }
    
    var indexTapPeople:Int!
    var doctors = DoctorsSingelton.share
    var patient = PatientSingelton.share
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
}

extension WritePatientToDoctorViewController: UITableViewDelegate, UITableViewDataSource{
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        doctors.data.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "writeCell", for: indexPath) as! BasicCell
        cell.setValue(data: doctors.data[indexPath.row])
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        doctors.data[indexPath.row].doctorHistory.append(patient.data[indexTapPeople])
        tableView.deselectRow(at: indexPath, animated: true)
        let alert = UIAlertController(title: "Пациент успешно записан", message: nil, preferredStyle: .actionSheet)
        let action = UIAlertAction(title: "OK", style: .default)
        alert.addAction(action)
        self.present(alert,animated: true)
    }
}
