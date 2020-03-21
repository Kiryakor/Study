//
//  B1.cpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "B1.hpp"

B1::B1(int b1){
    this->b1 = b1;
    cout << "Работает конструктор B1: параметр = " << b1 << endl;
};
B1::~B1(){
    cout << "~B1 сработал" << endl;
};
void B1::showB1(){
    cout << "B1 =  " << b1 << endl;
};
