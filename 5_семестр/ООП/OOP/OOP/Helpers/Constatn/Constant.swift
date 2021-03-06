//
//  Constant.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

enum Constant {
    enum Cell {
        case dostors
        case patient
        case addPatient
        
        func cellId() -> String {
            switch self {
            case .dostors:
                return "dostorsCellID"
            case .patient:
                return "patientCellId"
            case .addPatient:
                return "addPatientCellId"
            }
        }
    }
}
