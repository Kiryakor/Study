//
//  StatisticSingelton.swift
//  OOP
//
//  Created by Кирилл on 14.11.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

class StatisticSingelton {
    static let share = StatisticSingelton()
    
    private init(){}
    
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

class SaveStatistic {
    class func saveData(){
        let defaults = UserDefaults.standard
        let saveData = StatisticSingelton.share
        defaults.set(saveData.count, forKey: "count")
        defaults.set(saveData.weekday, forKey: "weekday")
    }
}

class LoadStatistic {
    class func loadData() {
        let defaults = UserDefaults.standard
        let saveData = StatisticSingelton.share
        let count:[Int] = defaults.array(forKey: "count") as? [Int] ?? [0,0,0,0,0,0]
        let weekday:[Int] = defaults.array(forKey: "weekday") as? [Int] ?? [0,0,0,0,0,0,0]
        
        saveData.count = count
        saveData.weekday = weekday
    }
}
