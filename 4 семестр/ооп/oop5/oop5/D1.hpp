//
//  D1.hpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef D1_hpp
#define D1_hpp

#include <iostream>
#include "B1.hpp"

using namespace std;

class D1:virtual public B1{
private:
    int d1;
public:
    D1(int b1,int d1);
    ~D1();
    void showD1();
};

#endif /* D1_hpp */
