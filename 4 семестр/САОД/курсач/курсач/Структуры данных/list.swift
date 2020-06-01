//
//  list.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

class Node:Equatable{
    static func == (lhs: Node, rhs: Node) -> Bool {
        return lhs.data.airTickets == rhs.data.airTickets
    }
    
    var next:Node?
    var data:Tickets
   
    init(_ data:Tickets) {
        self.next = nil
        self.data = data
    }
}

class CircularLinkedList{
    var last:Node?
    var currentTurn:Node?
    var size: Int {
        return returnAllData().count
    }
    
    init() {
        self.last = nil
        self.currentTurn = nil
    }
    
    func addToEmptyList(data:Tickets){
        let temp = Node(data)
        self.last = temp
        self.last?.next = self.last
        self.currentTurn = self.last?.next!
    }
    
    func addToListEnd(data:Tickets){
        if self.last == nil{
            self.addToEmptyList(data: data)
            return
        }
        let temp = Node(data)
        temp.next = self.last?.next
        self.last!.next! = temp
        self.last = temp
    }
    
    func popItem(data:String){
        var currentNode = self.last
        if currentNode == nil{ print("Данных нету") }
        while (currentNode != nil){
            if currentNode?.next?.data.airTickets == data{
                currentNode?.next = currentNode?.next?.next
                break
            }
            currentNode = currentNode?.next
            
            if currentNode == self.last{
                print("Данных таких нету")
                break
            }
        }
    }
    
    func traverse(){
        var currentNode = self.last?.next
        while (currentNode != nil){
            print(currentNode!.data)
            currentNode = currentNode?.next
            if currentNode == self.last?.next{
                break
            }
        }
    }
    
    func returnAllData() -> [Tickets] {
        var data:[Tickets] = []
        var currentNode = self.last?.next
        while (currentNode != nil){
            data.append(currentNode!.data)
            currentNode = currentNode?.next
            if currentNode == self.last?.next{
                return data
            }
        }
        return data
    }
    
    func retrieveTurn() -> Tickets{
        return self.currentTurn!.data
    }
    
    func updateTurn(){
        self.currentTurn = self.currentTurn?.next
    }
    
    //вывод номеров авиарейсов на которые куплены билеты на паспорту
    func printAirFlightNumber(passport:String) {
        var currentNode = self.last?.next
        while (currentNode != nil){
            print(currentNode!.data.airFlight)
            currentNode = currentNode?.next
            if currentNode == self.last?.next{
                break
            }
        }
    }
    
    func sort(){
        var output = returnAllData()
        for primaryindex in 0..<output.count {
            let key = output[primaryindex]
            var secondaryindex = primaryindex
            while secondaryindex > -1 {
                if key.passport < output[secondaryindex].passport {
                    output.remove(at: secondaryindex + 1)
                    output.insert(key, at: secondaryindex)
                }
                secondaryindex -= 1
            }
        }
        sortHelpers(data: output)
    }
    
    func sortHelpers(data:[Tickets]){
        print("1 - сохранить список")
        print("2 - сохранить и вывести")
        let a = Int(readLine() ?? "0")
        switch a {
        case 1:
            replaceData(data: data)
            break
        case 2:
            replaceData(data: data)
            printData()
            break
        default:
            break
        }
    }
    
    func printData(){
        var currentNode = self.last?.next
        while (currentNode != nil){
            print(currentNode!.data.passport)
            currentNode = currentNode?.next
            if currentNode == self.last?.next{
                break
            }
        }
    }
    
    func replaceData(data:[Tickets]){
        var currentNode = self.last?.next
        var i = 0
        while (currentNode != nil){
            currentNode?.data = data[i]
            i += 1
            currentNode = currentNode?.next
            if currentNode == self.last?.next{
                break
            }
        }
    }
    
    func passportInfo(numberAirFlight:String,table:HashTable){
        var currentNode = self.last
        if currentNode == nil{ print("Данных нету") }
        while (currentNode != nil){
            if currentNode?.data.airFlight == numberAirFlight{
                table.findForPassport(passport: currentNode?.data.passport ?? "")
            }
            currentNode = currentNode?.next
            
            if currentNode == self.last?.next{
                break
            }
        }
    }
}
