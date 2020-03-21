//
//  D2.cpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "D2.hpp"

D2::D2(int b1,int d2) : B1(b1){
    this->d2 = d2;
     cout << "Работает конструктор D2: параметр = " << d2 << endl;
};
D2::~D2(){
    cout << "~D2 сработал" << endl;
};
void D2::showD2(){
    cout << "D2 =  " << d2 << endl;
    showB1();
};
