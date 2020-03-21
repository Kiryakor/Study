//
//  flightInfo.cpp
//  mainCaod
//
//  Created by Кирилл on 16.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

struct flightInfo{
    string number; //«AAA-NNN», где AAA – код авиакомпании (буквы латиницы), NNN – порядковый номер авиарейса (цифры);
    string airline;
    string from;
    string to;
    string date;
    string time;
    string sizePlace;
    string freeSizePlace;
};
