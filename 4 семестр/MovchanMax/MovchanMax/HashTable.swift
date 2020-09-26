//
//  HashTable.swift
//  MovchanMax
//
//  Created by Кирилл on 20.08.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

protocol checkDriverIDProtocol {
    var driverId:String? { get set }
    func checkDriverId() -> Bool
}
extension checkDriverIDProtocol{
    func checkDriverId() -> Bool{
        let goodSet:Set<Character> = ["А", "В", "Е", "К", "М", "Н", "О", "Р", "С", "Т", "У", "Х"]
        if driverId!.count != 11 { return false }
        for (index,value) in driverId!.enumerated(){
            if (index < 2 || index > 6), !value.isNumber { return false }
            else if (index == 2 || index == 5), value != " " { return false }
            else if goodSet.contains(value), index < 3, index > 4  { return false }
        }
        return true
    }
}

struct Client:checkDriverIDProtocol {
    var driverId:String? //строка формата «RR AA NNNNNN», где RR – код региона (цифры), AA – серия (буквы из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х), NNNNNN – порядковый номер удостоверения (цифры). Код, серия и номер отделяются друг от друга пробелами;
    var fio:String
    var passport:String
    var adress:String
}

protocol checkNumberProtocol {
    var number:String? { get set }
    func checkNumber() -> Bool
}

extension checkNumberProtocol{
    func checkNumber() -> Bool{
        let goodSet:Set<Character> = ["А", "В", "Е", "К", "М", "Н", "О", "Р", "С", "Т", "У", "Х"]
        let charIndex:Set<Int> = [1,2,3,8,9]
        if number!.count != 9 { return false}
        for (index,value) in number!.enumerated(){
            if charIndex.contains(index), !value.isNumber { return false }
            else if index == 6, value != "-" { return false }
            else if !charIndex.contains(index), goodSet.contains(value){ return false }
        }
        return true
    }
}

struct Car:checkNumberProtocol {
    var number:String? //строка формата «ANNNAA-NN», где N –цифра, A – буква из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х;
    var marka:String?
    var color:String?
    var year:Int?
    var isHave:Bool?
    
    init() {
        self.number = nil
        self.marka = nil
        self.color = nil
        self.year = nil
        self.isHave = nil
    }
    
    init(number:String,marka:String,color:String,year:Int,isHave:Bool) {
        self.number = number
        self.marka = marka
        self.color = color
        self.year = year
        self.isHave = isHave
    }
}

//MARK: хеш таблица
class HashTable{
    var data:[Car] = []
    private let c = 2, d = 5
    
    init() { uppendNilData() }
    
    private func uppendNilData(){
        for _ in 0..<1500{ data.append(Car()) }
    }
    
    private func hash(newValue:String) -> Int {
        return abs(newValue.hashValue % data.count)
    }
    
    func newElement(car:Car){
        var index = hash(newValue: car.number!)
        var check = true
        while check {
            while index > data.count { uppendNilData() }
            if data[index].number == car.number {
                print("Пользователь с таким номером уже есть")
                check = false
                return
            }
            if data[index].number == nil{
                data[index] = car
                check = false
            }
            index += 1
        }
    }
    
    func removeElement(number:String){
        var index = hash(newValue: number)
        var tryCount = 0,check = true
        while check {
            index += c*tryCount + d*(tryCount^2)
            if index > data.count {
                print("Пользователя с таким номером нету")
                check = false
                return
            }else if data[index].number == number{
                data[index] = Car()
                check = false
                print("Пользвователь удален")
            }
            tryCount += 1
        }
    }
    
    func deleteAllPeople() {
        for i in 0..<data.count {
            if data[i].number != nil{ data[i] = Car() }
        }
    }
}


struct RentReturn:checkDriverIDProtocol,checkNumberProtocol {
    var driverId:String? //строка формата «RR AA NNNNNN», где RR – код региона (цифры), AA – серия (буквы из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х), NNNNNN – порядковый номер удостоверения (цифры). Код, серия и номер отделяются друг от друга пробелами;
    var number:String? //строка формата «ANNNAA-NN», где N –цифра, A – буква из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х;
    var dataFrom:String?
    var dataTo:String?
}

extension CircularDoublyLinkedList: Equatable {
    public static func == (lhs: CircularDoublyLinkedList, rhs: CircularDoublyLinkedList) -> Bool {
        return lhs.value?.number == rhs.value?.number
    }
}

public class CircularDoublyLinkedList{
    
    var value: RentReturn?
    var next: CircularDoublyLinkedList?
    var prev: CircularDoublyLinkedList?
    
    convenience init(_ value: RentReturn) {
        self.init()
        self.value = value
        defer {
            self.next = self
            self.prev = self
        }
    }
    
    func head(_ value: RentReturn) -> CircularDoublyLinkedList {
        if self.next == self {
            return self
        }
        var p = self
        if p.value?.number == value.number {
            return p
        }
        p = p.next!
        while p != self {
            if p.value?.number == value.number {
                break
            }
            p = p.next!
        }
        if p == self {
            //not found
            return self
        } else {
            //循环双向链表必然是有节点的，没有的话就应该 crash
            guard let pprev = p.prev, let pnext = p.next else { fatalError() }
            pprev.next = pnext
            pnext.prev = pprev
            p.next = self
            p.prev = self.prev
            self.prev = p
            p.prev?.next = p
            return p
        }
    }
    
    func insert(_ value: RentReturn) -> CircularDoublyLinkedList {
        let p = CircularDoublyLinkedList(value)
        p.next = self
        p.prev = self.prev
        self.prev = p
        p.prev?.next = p
        return p
    }

    /// - Returns: 返回新的头结点
    public func untail() -> CircularDoublyLinkedList? {
        if next == self {
            return nil
        }
        let tail = prev
        tail?.prev?.next = tail?.next
        tail?.next?.prev = tail?.prev
        return self
    }
}
