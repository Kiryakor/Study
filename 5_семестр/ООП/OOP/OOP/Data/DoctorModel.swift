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

struct DoctorModel: peopleProtocol {
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

struct PatientModel {
    var name: String
    var soname: String
    var problem: String
    var image: UIImage
    var data: Date
    
    var fullName:String {
        return name + " " + soname
    }
}

struct StatisticModel {
    var pickerData: [String] = ["Выборгский район",
                                "Московский район",
                                "Приморский район",
                                "Петроградский район",
                                "Василеостровский район",
                                "Невский район"]
    var count: [Int] = [0,0,0,0,0,0]
    
    var weekday: [Int] = [0,0,0,0,0,0,0]
    var day: [String] = ["Понедельник",
                         "Вторник",
                         "Среда",
                         "Четверг",
                         "Пятница",
                         "Суббота",
                         "Воскресенье"]
}
