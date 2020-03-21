//
//  main.cpp
//  OOP1
//
//  Created by Кирилл on 12.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include "t_end_d.hpp"

using namespace std;

int main() {
    //standart
    cout << "standart" << endl;
    t_end_d time1;
    time1.print();
    
    //parametrs
    cout << endl << "parametrs" << endl;
    tm *t;
    time_t ltime;
    time(&ltime);
    t = localtime(&ltime);
    t_end_d time2(t);
    time2.print();
    
    //coppy
    cout << endl << "coppy" << endl;
    t_end_d time3(time2);
    time3.print();
}
