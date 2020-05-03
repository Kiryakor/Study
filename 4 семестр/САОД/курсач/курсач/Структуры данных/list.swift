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
    
    init() {
        self.last = nil
        self.currentTurn = nil
    }
    
    func addToEmptyList(data:Tickets){
        //Will set the last node
        let temp = Node(data)
        self.last = temp
        //Creates the link (of one rn)
        self.last?.next = self.last
        //Sets the turns at the beggining of the list
        self.currentTurn = self.last?.next!
    }
    
    func addToListEnd(data:Tickets){
        if self.last == nil{
            self.addToEmptyList(data: data)
            return
        }
        //Connecting new node with the first, and setting previus last to link with new value
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
}
