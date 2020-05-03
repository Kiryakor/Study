//
//  Menu.swift
//  курсач
//
//  Created by Кирилл on 28.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

class Menu {
    
    var table = UserDefaults.passangerLoad()
    var tree = UserDefaults.flightLoad()
    var list = UserDefaults.ticketsLoad()
    
    func menu() {
        var check = true
        while check {
            print("")
            print("Меню")
            print("1 - регистрация нового пассажира")
            print("2 - удаление данных о пассажире")
            print("3 - просмотр всех зарегистрированных пассажиров. Результаты поиска – все сведения о найденном пассажире и номерах авиарейсов, на который он купил билет")
            print("4 - очистка данных о пассажирах")
            print("5 - поиск пассажира по его N паспорта")
            print("6 - поиск пассажира по его ФИО")
            print("7 - добавление нового авиарейса")
            print("8 - удаление сведений об авиарейсе;")
            print("9 - просмотр всех авиарейсов")
            print("10 - очистка данных об авиарейсах")
            print("11 - поиск пассажира по N авиарейса. Результаты поиска – все сведения о найденном авиарейсе, а также ФИО и номера паспортов пассажиров, которые купили билет на этот авиарейс")
            print("12 - поиск авиарейса по фрагментам названия аэропорта прибытия. Результаты поиска – список найденных авиарейсов с указанием номера авиарейса, аэропорта прибытия, даты отправления, времени отправления;")
            print("13 - регистрация продажи пассажиру авиабилета")
            print("14 - регистрация возврата пассажиром авиабилета")
            print("15 - выход и сохранение данных")
            print("")
            
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
                deleteAllPeople()
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
            case "11":
                findForAirFlight()
                break
            case "12":
                find12()
                break
            case "13":
                saleTickets()
                break
            case "14":
                returnTickets()
                break
            case "15":
                UserDefaults.flightSave(tree: tree)
                UserDefaults.ticketsSave(list: list)
                UserDefaults.passangerSave(table: table)
                check = false
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
            print("Пользователь упешно добавлен")
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
            print("Пользователь удален ")
        }else{ print("Вы ввели неверно данные") }
    }
    
    private func lookAllAirFligth(){
        let data:[Flight] = tree.values
        if data.count == 0 { print("Данных нету") }
        for i in data{
            print(i.number)
            print(i.company)
            print(i.from)
            print(i.to)
            print("")
        }
    }
    
    private func removeAllAirFligth(){
        tree.removeAllData()
        print("Все данные об авиарейсах удалены")
    }
    
    private func findForAirFlight(){
        print("Введите номер aвиарейса")
        let number = readLine()
        guard number != nil, number != "" else { print("Вы ввели неверно данные"); return}
        
        if Flight.checkNumber(number: number!){
            let data:[Flight] = tree.values
            for i in data{
                if i.number == number!{
                    i.printData()
                }
            }
        }else{ print("Вы ввели неверно данные") }
    }
    
    private func find12(){
        print("Введите название аэропорта или часть названия ")
        let name = readLine()
        guard name != "", name != nil else { return }
        
        let result:[Flight] = tree.searchBM(to: name!)
        if result.count == 0{ print("Данных нету") }
        for i in result{
            i.printData()
            print("")
        }
    }
    
    private func saleTickets(){
        print("Введите номер паспорта")
        let passport = readLine()
        guard passport != nil, true == Passenger.checkPassport(passport: passport!) else {
            print("некорректные данные")
            return
        }
        if table.returnPeople(passportNumber: passport!) == nil{
            print("Пользователя с таким паспортом нету")
            return
        }
        
        print("Введите номер авиарейса")
        let airFlight = readLine()
        guard airFlight != nil, true == Flight.checkNumber(number: airFlight!) else {
            print("некорректные данные")
            return
        }
        
        if tree.searchBM(to: airFlight!).count == 0{
            print("Такого авиарейса нету")
        }
        
        print("Введите номер битела")
        let airTickets = readLine()
        guard airTickets != nil, true == Tickets.checkAirTickets(airTickets: airTickets!) else {
            print("некорректные данные")
            return
        }
        
        let tickets = Tickets(passport: passport!, airFlight: airFlight!, airTickets: airTickets!)
        
        if tree.freePlace(company: airFlight!){
            list.addToListEnd(data: tickets)
            tree.minusFreePlace(number: airFlight!)
        }else{
            print("Нету свободных мест")
        }
    }
    
    private func returnTickets(){
        print("Введите номер билета")
        let airTickets = readLine()
        guard airTickets != nil, true == Tickets.checkAirTickets(airTickets: airTickets!) else {
            print("некорректные данные")
            return
        }
        
        list.popItem(data: airTickets!)
    }
}
