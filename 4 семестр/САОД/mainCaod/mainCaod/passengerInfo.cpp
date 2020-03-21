//
//  passengerInfo.cpp
//  mainCaod
//
//  Created by Кирилл on 16.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

//Данные о каждом пассажире должны содержать:
// No паспорта – строка формата «NNNN-NNNNNN», где N –цифры;
// Место и дата выдачи паспорта – строка;
// ФИО – строка;
// Дата рождения – строка.
//Примечание – длина строк (кроме No паспорта) определяется студентом самостоятельно.

struct passengerInfo{
    string numberPassport;
    string place;
    string fio;
    string date;
};
