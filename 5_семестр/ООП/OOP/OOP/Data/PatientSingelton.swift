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
    var data: [DoctorModel] = []
    static let share = PatientSingelton()
}

class SavePatient {
    class func saveData(){
        let defaults = UserDefaults.standard
        let saveData = PatientSingelton.share
        var name:[String] = []
        var soname:[String] = []
        var profession:[String] = []
        var date:[Date] = []
        var image:[Data] = []
        for i in saveData.data{
            name.append(i.name)
            soname.append(i.soname)
            profession.append(i.profession)
            date.append(i.data)
            image.append(i.image.pngData()!)
        }
        defaults.set(name, forKey: "patientName")
        defaults.set(date, forKey: "patientDate")
        defaults.set(soname, forKey: "patientSoname")
        defaults.set(profession, forKey: "patientProfession")
        defaults.set(image, forKey: "imageProfession")
    }
}

class LoadPatient {
    class func loadData() {
        let defaults = UserDefaults.standard
        let saveData = PatientSingelton.share
        let name:[String] = defaults.array(forKey: "patientName") as? [String] ?? []
        let date:[Date] = defaults.array(forKey: "patientDate") as? [Date] ?? []
        let soname:[String] = defaults.array(forKey: "patientSoname") as? [String] ?? []
        let profession:[String] = defaults.array(forKey: "patientProfession") as? [String] ?? []
        let image:[Data] = defaults.array(forKey: "imageProfession") as? [Data] ?? []
        for i in 0..<name.count{
            let model = DoctorModel(name: name[i], soname: soname[i], profession: profession[i], image: UIImage(data: image[i])!, data: date[i])
            saveData.data.append(model)
        }
    }
}
