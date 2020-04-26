//
//  main.swift
//  саод
//
//  Created by Кирилл on 25.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation


//поиск пассажира по «No паспорта». Результаты поиска – все сведения
//о найденном пассажире и номерах авиарейсов, на который он купил
//билет

class Main {
    
    var table = HashTable()
    var tree = AVLTree()
    var list = CircularLinkedList()
    
    func menu() {
        print("1 - регистрация нового пассажира")
        print("2 - удаление данных о пассажире")
        print("3 - просмотр всех зарегистрированных пассажиров")
        print("4 - очистка данных о пассажирах")
        
        let value = readLine()
        switch value {
        case "1":
            registNewPeople()
            break
        case "2":
            deletePeopleData()
            break
        case "3":
            lookAllPeople()
            break
        case "4":
            deletePeopleData()
            break
        case "5":
            findPeople()
            break
        default:
            print("error")
        }
    }
    
    private func registNewPeople(){
        var people = Passenger()
        if people.registerPeople(){
            table.newElement(passenger: people)
        }
    }
    
    private func deletePeopleData(){
        print("Введите номер паспорта пассажира")
        let passportNumber = readLine()
        if Passenger.checkPassport(passport: passportNumber){
            table.removeElement(passportNumber: passportNumber!)
        }else{ print("Вы ввели неверно данные") }
    }
    
    private func lookAllPeople(){
        table.lookAllPeple()
    }
    
    private func deleteAllPeople(){
        table.deleteAllPeople()
    }
    
    private func findPeople(){
        print("Введите номер паспорта пассажира")
        let passportNumber = readLine()
        guard passportNumber != nil, passportNumber != "" else {
            print("Вы ввели неверно данные");
            return
        }
        guard let people = table.returnPeople(passportNumber: passportNumber!) else {
            print("Пользователя с таким паспортом нету");
            return
        }
        
        print("ФИО  - \(people.fio!)")
        print("Номер паспорта - \(people.passport!)")
        print("Дата и место получения - \(people.date!)")
        print("Место получения - \(people.place!)")
        
        list.printAirFlightNumber(passport: people.passport!)
    }
}


let a = Main()
a.menu()
