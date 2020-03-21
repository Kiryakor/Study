//
//  D2.hpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef D2_hpp
#define D2_hpp

#include <iostream>
#include "B1.hpp"

using namespace std;

class D2:virtual private B1{
private:
    int d2;
public:
    D2(int b1,int d2);
    ~D2();
    void showD2();
};

#endif /* D2_hpp */
