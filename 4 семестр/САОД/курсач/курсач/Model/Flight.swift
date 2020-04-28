//
//  Flight.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation


//MARK: авиарейсы
struct Flight {
    var number:String //«AAA-NNN», где AAA – код авиакомпании (буквы латиницы), NNN – порядковый номер авиарейса (цифры);
    var company:String
    var from:String
    var to:String
    var date:String
    var time:String
    var count:Int
    var countFree:Int
    
    init() {
         self.number = ""
         self.company = ""
         self.from = ""
         self.to = ""
         self.date = ""
         self.time = ""
         self.count = -1
         self.countFree = -1
     }
    
    static func checkNumber(number:String) -> Bool {
        guard number.count == 7 else { return false}
        var count = 0
        for i in number{
            if count < 3 && i.isSymbol { return false }
            if count == 3 && i != "-" { return false }
            if count > 4 && !i.isNumber { return false }
            count += 1
        }
        return true
    }

    mutating func addNewFlight()->Bool{
        print("Введите номер авиарейса в формате AAA-NNN")
        self.number = readLine()!
        guard self.number != "", Flight.checkNumber(number: self.number) == true else { return false}
        
        print("Введите название компании")
        self.company = readLine()!
        guard self.company != "" else { return false }
        
        print("Введите место отправки")
        self.from = readLine()!
        guard self.from != "" else { return false }
        
        print("Введите место прибытия")
        self.to = readLine()!
        guard self.to != "" else { return false }
        
        print("Введите дату отправления")
        self.date = readLine()!
        guard self.date != "" else { return false }
        
        print("Введите время отправления")
        self.time = readLine()!
        guard self.time != "" else { return false }
        
        print("Введите кол-во мест")
        self.count = Int(readLine()!)!
        guard count != -1 else { return false }
        
        print("Введите кол-во свободных мест")
        self.countFree = Int(readLine()!)!
        guard self.countFree != -1 else { return false }
        
        if count < countFree { return false }
        
        return true
    }

     func printData(){
        print("номер рейса \(number)")
        print("название компании \(company)")
        print("откуда \(from)")
        print("куда \(to)")
        print("дату рейсаа \(date)")
        print("время рейса \(time)")
        print("кол-во мест \(count)")
        print("кол-во свободных мест \(countFree)")
    }
}
