//
//  D4.hpp
//  oop5
//
//  Created by Кирилл on 19.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef D4_hpp
#define D4_hpp

#include <stdio.h>
#include "D1.hpp"
#include "D2.hpp"
#include "B2.hpp"
#include "B1.hpp"

using namespace std;

class D4:public D1,public D2, private B2{
private:
    int d4;
public:
    D4(int b1,int b2,int d1,int d2,int d4);
    ~D4();
    void showD4();
};

#endif /* D4_hpp */
