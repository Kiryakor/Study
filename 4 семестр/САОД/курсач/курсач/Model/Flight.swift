//
//  Flight.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation


//MARK: авиарейсы
struct Flight {
    var number:String //«AAA-NNN», где AAA – код авиакомпании (буквы латиницы), NNN – порядковый номер авиарейса (цифры);
    var company:String
    var from:String
    var to:String
    var date:String
    var time:String
    var count:Int
    var countFree:Int
    
    func checkNumber(number:String) -> Bool {
        guard number.count == 7 else { return false}
        var count = 0
        for i in number{
            if count < 3 && !i.isSymbol { return false }
            if count == 3 && i != "-" { return false }
            if count > 4 && !i.isNumber { return false }
            count += 1
        }
        return true
    }

}
