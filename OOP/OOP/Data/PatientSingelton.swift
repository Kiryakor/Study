//
//  PatientSingelton.swift
//  OOP
//
//  Created by Кирилл on 31.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class PatientSingelton {
    private init(){}
    var data: [PeopleModel] = [PeopleModel(name: "ivan", soname: "Petrov", profession: "работяга", image: UIImage(systemName: "table")!)]
    static let share = PatientSingelton()
}
