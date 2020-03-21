//
//  t_end_d.hpp
//  OOP1
//
//  Created by Кирилл on 20.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef t_end_d_hpp
#define t_end_d_hpp

#include <stdio.h>
#include <ctime>

class t_end_d{
private:
    tm *t;
public:
    t_end_d();
    t_end_d(tm*);
    t_end_d(const t_end_d& t);
    ~t_end_d();
    void print();
};

#endif /* t_end_d_hpp */
