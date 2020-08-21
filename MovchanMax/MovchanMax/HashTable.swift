//
//  HashTable.swift
//  MovchanMax
//
//  Created by Кирилл on 20.08.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

struct Client {
    var driverId:String //строка формата «RR AA NNNNNN», где RR – код региона (цифры), AA – серия (буквы из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х), NNNNNN – порядковый номер удостоверения (цифры). Код, серия и номер отделяются друг от друга пробелами;
    var fio:String
    var passport:String
    var adress:String
    
    func checkDriverId() -> Bool{
        let goodSet:Set<Character> = ["А", "В", "Е", "К", "М", "Н", "О", "Р", "С", "Т", "У", "Х"]
        if driverId.count != 11 { return false }
        for (index,value) in driverId.enumerated(){
            if (index < 2 || index > 6), !value.isNumber { return false }
            else if (index == 2 || index == 5), value != " " { return false }
            else if goodSet.contains(value), index < 3, index > 4  { return false }
        }
        return true
    }
}

struct Car {
    var number:String //строка формата «ANNNAA-NN», где N –цифра, A – буква из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х;
    var marka:String
    var color:String
    var year:Int
    var isHave:Bool
    
    func checkNumber() -> Bool{
        let goodSet:Set<Character> = ["А", "В", "Е", "К", "М", "Н", "О", "Р", "С", "Т", "У", "Х"]
        let charIndex:Set<Int> = [1,2,3,8,9]
        if number.count != 9 { return false}
        for (index,value) in number.enumerated(){
            if charIndex.contains(index), !value.isNumber { return false }
            else if index == 6, value != "-" { return false }
            else if !charIndex.contains(index), goodSet.contains(value){ return false }
        }
        return true
    }
}
