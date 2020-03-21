//
//  B2.cpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "B2.hpp"

B2::B2(int b2){
    this->b2 = b2;
    cout << "Работает конструктор B2: параметр = " << b2 << endl;
};
B2::~B2(){
   cout << "~B2 сработал" << endl;
};
void B2::showB2(){
    cout << "B2 =  " << b2 << endl;
};
