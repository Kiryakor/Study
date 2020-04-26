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
        var check = true
        while check {
            print("1 - регистрация нового пассажира")
            print("2 - удаление данных о пассажире")
            print("3 - просмотр всех зарегистрированных пассажиров")
            print("4 - очистка данных о пассажирах")
            print("5 - поиск пассажира по его N паспорта")
            print("6 - поиск пассажира по его ФИО")
            print("7 - добавление нового авиарейса")
            print("8 - удаление сведений об авиарейсе;")
            print("9 - просмотр всех авиарейсов")
            print("10 - очистка данных об авиарейсах")
            
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
                findForPassport()
                break
            case "6":
                findForFio()
                break
            case "7":
                addNewAirFlight()
                break
            case "8":
                removeAirFligth()
                break
            case "9":
                lookAllAirFligth()
                break
            case "10":
                removeAllAirFligth()
                break
            default:
                check = false
            }
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
    
    private func findForPassport(){
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
    
    private func findForFio(){
        print("Введите номер ФИО пассажира")
        let fio = readLine()
        guard fio != nil, fio != "" else {
            print("Вы ввели неверно данные");
            return
        }
        if !table.findForFIO(fio: fio!){
            print("Таких пользователей нету")
        }
    }
    
    private func addNewAirFlight(){
        var flight = Flight()
        if flight.addNewFlight(){
            tree.insert(value: flight)
        }else{ print("Вы ввели неверно данные") }
    }
    
    private func removeAirFligth(){
       print("Введите номер aвиарейса")
        let number = readLine()
        guard number != nil, number != "" else { print("Вы ввели неверно данные"); return}
        if Flight.checkNumber(number: number!){
            tree.remove(value: number!)
        }else{ print("Вы ввели неверно данные") }
    }
    
    //MARK: допилить вывод данных
    private func lookAllAirFligth(){
        let data:[Flight] = tree.values
        for i in data{
            print(i.number)
        }
    }
    
    private func removeAllAirFligth(){
        tree = AVLTree()
    }
}


let a = Main()
a.menu()
