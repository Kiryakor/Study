//
//  D1.cpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "D1.hpp"

D1::D1(int b1,int d1) : B1(b1){
    this->d1 = d1;
    cout << "Работает конструктор D1: параметр = " << d1 << endl;
};
D1::~D1(){
    cout << "~D1 сработал" << endl;
};
void D1::showD1(){
    cout << "D2 =  " << d1 << endl;
    showB1();
};
