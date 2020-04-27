//
//  Tickets.swift
//  курсач
//
//  Created by Кирилл on 26.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

import Foundation

struct Tickets {
    var passport: String
    var airFlight: String
    var airTickets: String
    
    func prindData()  {
        print("Пасспорт пассажира \(passport)")
        print("номер рейса \(airFlight)")
        print("номер билета \(airTickets)")
    }
    
    static func checkAirTickets(airTickets:String) -> Bool{
        guard airTickets.count == 9 else { return false }
        for i in airTickets{
            if i.isNumber == false{
                return false
            }
        }
        return true
    }
}
