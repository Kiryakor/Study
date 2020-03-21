//
//  t_end_d.cpp
//  OOP1
//
//  Created by Кирилл on 20.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "t_end_d.hpp"
#include <iostream>

t_end_d::t_end_d(){
    time_t ltime;
    time(&ltime);
    t = localtime(&ltime);
}

t_end_d::t_end_d(tm* t){
    this->t = t;
}

t_end_d::t_end_d(const t_end_d& t){
    this->t = t.t;
}

t_end_d::~t_end_d(){
}

void t_end_d::print(){
    std::cout << "time " << t->tm_sec << ":" << t->tm_min << ":" << t->tm_hour << std::endl;
    std::cout << "date " << t->tm_mday << "." << t->tm_mon << "." << t->tm_year << std::endl;
}
