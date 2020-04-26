//
//  Passenger.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

//MARK: пассажиры
struct Passenger {
    var passport:String? //NNNN-NNNNNN проверка формата
    var place:String?
    var fio:String?
    var date:String?
    
    init() {
        self.passport = nil
        self.place = nil
        self.fio = nil
        self.date = nil
    }
    
    init(passport:String,place:String,fio:String,data:String) {
        self.passport = passport
        self.place = place
        self.fio = fio
        self.date = data
    }
    
    mutating func registerPeople()->Bool{
        print("Введите ФИО пользователя")
        self.fio = readLine()
        guard self.fio != nil, self.fio != "" else { errorReadData(); return false}
        
        print("Введите дату рожденния пользователя в формате yyyy-MM-dd")
        self.date = readLine()
        guard self.date != nil, checkData(date: self.date), self.date != "" else { errorReadData(); return false}
        
        print("Введите место и дату выдачи паспорта")
        self.place = readLine()
        guard self.place != nil, self.place != "" else { return false}
        
        print("Введите номер паспорта в формате NNNN-NNNNNN")
        self.passport = readLine()
        guard self.passport != nil, self.passport != "", Passenger.checkPassport(passport: self.passport) else { errorReadData(); return false}
        return true
    }
    
    private func checkData(date:String?) -> Bool{
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd"
        guard let date = date, let _ = dateFormatter.date(from:date) else { return false}
        return true
    }
    
    
    static func checkPassport(passport:String?) -> Bool{
        guard let passport = passport, passport.count == 11 else { return false }
        var count = 0
        for i in passport{
            if i != "-", count == 4 { return false }
            if !i.isNumber, count != 4 { return false }
            count += 1
        }
        return true
    }
    
    private func errorReadData(){
        print("Вы ввели неверно данные")
    }
}
