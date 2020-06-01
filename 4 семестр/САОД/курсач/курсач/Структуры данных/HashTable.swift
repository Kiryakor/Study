//
//  HashTable.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

//MARK: хеш таблица
class HashTable{
    var data:[Passenger] = []
    private let c = 2, d = 5
    
    init() { uppendNilData() }
    
    private func uppendNilData(){
        for _ in 0..<1500{ data.append(Passenger()) }
    }
    
    private func hash(newValue:String) -> Int {
        return abs(newValue.hashValue % data.count)
    }
    
    func newElement(passenger:Passenger){
        var index = hash(newValue: passenger.passport!)
        var tryCount = 0,check = true
        while check {
            index += c*tryCount + d*(tryCount^2)
            while index > data.count { uppendNilData() }
            if data[index].passport == passenger.passport {
                print("Пользователь с таким паспортом уже есть")
                check = false
                return
            }
            if data[index].passport == nil{
                data[index] = passenger
                check = false
            }
            tryCount += 1
        }
    }
    
    func removeElement(passportNumber:String){
        var index = hash(newValue: passportNumber)
        var tryCount = 0,check = true
        while check {
            index += c*tryCount + d*(tryCount^2)
            if index > data.count {
                print("Пользователя с таким паспортом нету")
                check = false
                return
            }
            if data[index].passport == passportNumber{
                data[index] = Passenger()
                check = false
                print("Пользвователь удален")
            }
            tryCount += 1
        }
    }
    
    func lookAllPeple() {
        var count = 0
        for i in data{
            if i.passport != nil{
                count += 1
                print(i.date!," ",i.fio!," ",i.passport!," ",i.place!)
            }
        }
        if count == 0{
            print("Пользователей ещё нету")
        }
    }
    
    func deleteAllPeople() {
        for i in 0..<data.count {
            if data[i].passport != nil{ data[i] = Passenger() }
        }
        print("Все данные о пассажирах удалены")
    }
    
    func returnPeople (passportNumber:String) -> Passenger?{
        var index = hash(newValue: passportNumber)
        var tryCount = 0,check = true
        while check {
            index += c*tryCount + d*(tryCount^2)
            if index > data.count { return nil }
            if data[index].passport == passportNumber{
                check = false
                return data[index]
            }
            tryCount += 1
        }
    }
    
    func findForFIO(fio:String) -> Bool{
        var check = false
        for i in data{
            if i.fio == fio{
                print("ФИО - \(fio)   номер паспорта - \(i.passport!)")
                check = true
            }
        }
        return check
    }
    
    func findForPassport(passport:String){
        for i in data{
            if i.passport == passport{
                print("ФИО - \(i.fio!)   номер паспорта - \(i.passport!)")
            }
        }
    }
}
