//
//  DoctorsSingelton.swift
//  OOP
//
//  Created by Кирилл on 31.10.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import UIKit

class DoctorsSingelton {
    private init(){}
    var data: [DoctorModel] = []
    static let share = DoctorsSingelton()
}

class SaveDoctors {
    class func saveData(){
        let defaults = UserDefaults.standard
        let saveData = DoctorsSingelton.share
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
        defaults.set(name, forKey: "doctorsName")
        defaults.set(date, forKey: "doctorsDate")
        defaults.set(soname, forKey: "doctorsSoname")
        defaults.set(profession, forKey: "doctorsProfession")
        defaults.set(image, forKey: "imageDoctors")
    }
    
    class func saveDataHistory(){
        let defaults = UserDefaults.standard
        let saveData = DoctorsSingelton.share
        var name:[String] = []
        var soname:[String] = []
        var profession:[String] = []
        var date:[Date] = []
        var image:[Data] = []
        var index:[Int] = []
        for i in 0..<saveData.data.count{
            for j in saveData.data[i].doctorHistory{
                name.append(j.name)
                soname.append(j.soname)
                profession.append(j.profession)
                date.append(j.data)
                image.append(j.image.pngData()!)
                index.append(i)
            }
        }
        defaults.set(name, forKey: "doctorsNameHistory")
        defaults.set(date, forKey: "doctorsDateHistory")
        defaults.set(soname, forKey: "doctorsSonameHistory")
        defaults.set(profession, forKey: "doctorsProfessionHistory")
        defaults.set(image, forKey: "imageDoctorsHistory")
        defaults.set(index, forKey: "indexHistory")
    }
}

class LoadDoctors {
    class func loadData() {
        let defaults = UserDefaults.standard
        let saveData = DoctorsSingelton.share
        let name:[String] = defaults.array(forKey: "doctorsName") as? [String] ?? []
        let date:[Date] = defaults.array(forKey: "doctorsDate") as? [Date] ?? []
        let soname:[String] = defaults.array(forKey: "doctorsSoname") as? [String] ?? []
        let profession:[String] = defaults.array(forKey: "doctorsProfession") as? [String] ?? []
        let imageDoctors:[Data] = defaults.array(forKey: "imageDoctors") as? [Data] ?? []
        for i in 0..<name.count{
            let model = DoctorModel(name: name[i], soname: soname[i], profession: profession[i], image: UIImage(data: imageDoctors[i])!, data: date[i])
            saveData.data.append(model)
        }
    }
    
    class func loadDataHistory() {
        let defaults = UserDefaults.standard
        let saveData = DoctorsSingelton.share
        let name:[String] = defaults.array(forKey: "doctorsNameHistory") as? [String] ?? []
        let date:[Date] = defaults.array(forKey: "doctorsDateHistory") as? [Date] ?? []
        let soname:[String] = defaults.array(forKey: "doctorsSonameHistory") as? [String] ?? []
        let profession:[String] = defaults.array(forKey: "doctorsProfessionHistory") as? [String] ?? []
        let imageDoctors:[Data] = defaults.array(forKey: "imageDoctorsHistory") as? [Data] ?? []
        let index:[Int] = defaults.array(forKey: "indexHistory") as? [Int] ?? []
        
        for i in 0..<name.count{
            let model = DoctorModel(name: name[i], soname: soname[i], profession: profession[i], image: UIImage(data: imageDoctors[i])!, data: date[i])
            saveData.data[index[i]].doctorHistory.append(model)
        }
    }
}
