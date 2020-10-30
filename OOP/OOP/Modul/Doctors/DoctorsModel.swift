//
//  DoctorsModel.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation
import UIKit

struct DoctorsModel {
    let name: String
    let soname: String
    let profession: String
    let image: UIImage
    
    var fullName:String {
        return name + " " + soname
    }
}
