//
//  D4.cpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "D4.hpp"

D4::D4(int b1,int b2,int d1,int d2,int d4) : D2(b1,d2),B2(b2),D1(b1,d1),B1(b1){
    this->d4 = d4;
     cout << "Работает конструктор D3: параметр = " << d4 << endl;
};
D4::~D4(){
    cout << "~D2 сработал" << endl;
};
void D4::showD4(){
    cout << "D4 =  " << d4 << endl;
    showD2();
    showD1();
    showB2();
};
