//
//  Date.cpp
//  OOP1
//
//  Created by Кирилл on 12.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "Date.hpp"
#include <iostream>

using namespace std;

void Date::print(){
    cout << day << "." << month << "." << year << endl;
}

bool Date::isRange(int value, int min, int max) {
    if (value < min)
        return false;
    if (value > max)
        return false;
    return true;
}

bool Date::isValid(){
    if (year > 2020)
        return false;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return isRange(day, 1, 31);
        case 2:
            if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
                return isRange(day, 1, 29);
            else
                return isRange(day, 1, 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return isRange(day, 1, 30);
        default:
            return false;
    }
}


void Date::get(int date[]){
    day = date[0];
    month = date[1];
    year = date[2];
}

void Date::check(){
    if (isValid()){
        cout << "Date is good" << endl;
    }else{
        cout << "Date is not good" << endl;
    }
}
