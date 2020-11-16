//
//  DoctorsModel.swift
//  OOP
//
//  Created by Кирилл on 25.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation
import UIKit

protocol peopleProtocol{
    var name:String { get set }
    var soname:String { get set }
    var profession:String { get set }
    var image: UIImage { get set }
    var data: Date { get set }
}

struct PeopleModel: peopleProtocol {
    var name: String
    var soname: String
    var profession: String
    var image: UIImage
    var data: Date
    
    var fullName:String {
        return name + " " + soname
    }
    
    var doctorHistory:[peopleProtocol] = []
}
