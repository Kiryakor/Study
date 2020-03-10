//
//  Complex.hpp
//  oop3
//
//  Created by Кирилл on 08.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Complex{
private:
    double a,b,r,coss,sinn;
public:
    Complex(double a,double b);
    Complex();
    string print();
    void fromString(string value);
    Complex operator*(Complex complex);
    Complex operator/(Complex complex);
    Complex operator-(Complex complex);
    Complex operator+(Complex complex);
    bool operator=(Complex complex);
    bool operator>(Complex complex);
    bool operator<(Complex complex);
};

#endif /* Complex_hpp */

