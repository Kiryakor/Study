//
//  Date.hpp
//  OOP1
//
//  Created by Кирилл on 12.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

class Date{
private:
    int day, month, year;
    bool isValid();
    bool isRange(int value, int min, int max);
public:
    void print();
    void check();
    void get(int date[]);
};

#endif /* Date_hpp */
