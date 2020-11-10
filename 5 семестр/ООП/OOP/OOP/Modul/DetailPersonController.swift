//
//  DetailPersonController.swift
//  OOP
//
//  Created by Кирилл on 01.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DetailPersonController: UIViewController {

    var index:Int!
    var data = PatientSingelton.share
    @IBOutlet weak var peopleImageView: UIImageView!
    @IBOutlet weak var fullNameLabel: UILabel!
    @IBOutlet weak var professionLabel: UILabel!
    @IBOutlet weak var writeButton: UIButton!{
        didSet{
            writeButton.clipsToBounds = true
            writeButton.layer.cornerRadius = 10
            writeButton.backgroundColor = #colorLiteral(red: 0.1485694902, green: 0.4383754773, blue: 0.615123057, alpha: 1)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .edit, target: self, action: #selector(editProfile))
        title = "Пациент"
    }
    
    override func viewDidAppear(_ animated: Bool) {
        peopleImageView.image = data.data[index].image
        fullNameLabel.text = data.data[index].fullName
        professionLabel.text = data.data[index].profession
    }
    
    @IBAction func writePeople(_ sender: UIButton) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "WritePatientToDoctorViewController") as! WritePatientToDoctorViewController
        vc.indexTapPeople = index
        navigationController?.pushViewController(vc,animated: true)
    }
    
    @objc func editProfile(){
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "EditPatientViewController") as! EditPatientViewController
        vc.index = index
        navigationController?.pushViewController(vc,animated: true)
    }
}
