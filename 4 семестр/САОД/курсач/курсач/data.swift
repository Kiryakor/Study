//
//  Save:Load .swift
//  курсач
//
//  Created by Кирилл on 03.05.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

extension UserDefaults{
    static func passangerSave(table:HashTable){
        var passport:[String] = []
        var place:[String] = []
        var fio:[String] = []
        var data:[String] = []
        
        for i in table.data{
            if i.date != nil{
                passport.append(i.passport!)
                place.append(i.place!)
                fio.append(i.fio!)
                data.append(i.date!)
            }
        }
        UserDefaults.standard.set(passport, forKey: "passportPassenger")
        UserDefaults.standard.set(place, forKey: "placePassenger")
        UserDefaults.standard.set(fio, forKey: "fioPassenger")
        UserDefaults.standard.set(data, forKey: "datePassenger")
    }
    
    static func passangerLoad() -> HashTable{
        let table = HashTable()
        let passport = UserDefaults.standard.array(forKey: "passportPassenger") ?? []
        let place = UserDefaults.standard.array(forKey: "placePassenger") ?? []
        let fio = UserDefaults.standard.array(forKey: "fioPassenger") ?? []
        let data = UserDefaults.standard.array(forKey: "datePassenger") ?? []
        if passport.count != place.count || place.count != fio.count || fio.count != data.count{
            print("Ошибка при загрузке данные в Хэш-таблицу")
            return table
        }
        
        if passport.count > 0{
            for i in 0..<passport.count{
                let people = Passenger(passport: passport[i] as! String, place: place[i] as! String, fio: fio[i] as! String, data: data[i] as! String)
                table.newElement(passenger: people)
            }
        }
        return table
    }
    
    static func ticketsSave(list:CircularLinkedList){
        var passport:[String] = []
        var airFlight:[String] = []
        var airTickets:[String] = []
        
        let data = list.returnAllData()
        for i in data{
            passport.append(i.passport)
            airFlight.append(i.airFlight)
            airTickets.append(i.airTickets)
        }
        
        UserDefaults.standard.set(passport, forKey: "passportTickets")
        UserDefaults.standard.set(airFlight, forKey: "airFlightTickets")
        UserDefaults.standard.set(airTickets, forKey: "airTicketsTickets")
    }
    
    static func ticketsLoad() -> CircularLinkedList{
        let list = CircularLinkedList()
        let passport = UserDefaults.standard.array(forKey: "passportTickets") ?? []
        let airFlight = UserDefaults.standard.array(forKey: "airFlightTickets") ?? []
        let airTickets = UserDefaults.standard.array(forKey: "airTicketsTickets") ?? []
        
        if passport.count != airFlight.count || airFlight.count != airTickets.count{
            print("Ошибка при загрузке данных в Список")
            return list
        }
        
        if passport.count > 0{
            for i in 0..<passport.count{
                let data = Tickets(passport: passport[i] as! String, airFlight: airFlight[i] as! String, airTickets: airTickets[i] as! String)
                list.addToListEnd(data: data)
            }
        }
        return list
    }
    
    static func flightSave(tree:AVLTree){
        var number:[String] = []
        var company:[String] = []
        var from:[String] = []
        var to:[String] = []
        var date:[String] = []
        var time:[String] = []
        var count:[Int] = []
        var countFree:[Int] = []
        
        for i in tree.values{
            number.append(i.number)
            company.append(i.company)
            from.append(i.from)
            to.append(i.to)
            date.append(i.date)
            time.append(i.time)
            count.append(i.count)
            countFree.append(i.countFree)
        }
        
        UserDefaults.standard.set(number, forKey: "numberAVLTree")
        UserDefaults.standard.set(company, forKey: "companyAVLTree")
        UserDefaults.standard.set(from, forKey: "fromAVLTree")
        UserDefaults.standard.set(to, forKey: "toAVLTree")
        UserDefaults.standard.set(date, forKey: "dateAVLTree")
        UserDefaults.standard.set(time, forKey: "timeAVLTree")
        UserDefaults.standard.set(count, forKey: "countAVLTree")
        UserDefaults.standard.set(countFree, forKey: "countFreeAVLTree")
    }
    
    static func flightLoad() -> AVLTree{
        let tree = AVLTree()
        let number = UserDefaults.standard.array(forKey: "numberAVLTree") ?? []
        let company = UserDefaults.standard.array(forKey: "companyAVLTree") ?? []
        let from = UserDefaults.standard.array(forKey: "fromAVLTree") ?? []
        let to = UserDefaults.standard.array(forKey: "toAVLTree") ?? []
        let date = UserDefaults.standard.array(forKey: "dateAVLTree") ?? []
        let time = UserDefaults.standard.array(forKey: "timeAVLTree") ?? []
        let count = UserDefaults.standard.array(forKey: "countAVLTree") ?? []
        let countFree = UserDefaults.standard.array(forKey: "countFreeAVLTree") ?? []
        
        if number.count != company.count || from.count != to.count || date.count != time.count || count.count != countFree.count {
            print("Ошибка при загрузке данных в Дерево")
            return tree
        }
        
        if number.count > 0 {
            for i in 0..<number.count{
                var data = Flight()
                data.number = number[i] as! String
                data.company = company[i] as! String
                data.from = from[i] as! String
                data.to = to[i] as! String
                data.date = date[i] as! String
                data.time = time[i] as! String
                data.count = count[i] as! Int
                data.countFree = countFree[i] as! Int
                tree.insert(value: data)
            }
        }
        
        return tree
    }
}
