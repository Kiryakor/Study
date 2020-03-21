//
//  Complex.cpp
//  oop3
//
//  Created by Кирилл on 08.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <cmath>
#include "Complex.hpp"

Complex operator/(Complex complex,Complex complex2){
    double real = complex2.r/complex.r*cos(complex2.coss-complex.coss);
    double imag = complex2.r/complex.r*sin(complex2.sinn-complex.sinn);
    return Complex(real,imag);
}

void Complex::fromString(string value){
    string line = "";
    int count = 0;
    for (int i=0;i<value.length();i++){
        if (value[i]!=' ' && value[i]!='i' && value[i]!='+'){
            line+= value[i];
        }else{
            if (count==0){
                this->coss = atoi(line.c_str());
                count++;
            }
            line = "";
        }
    }
    this->sinn = atoi(line.c_str());
}

Complex::Complex(double a,double b){
    this->a = a;
    this->b = b;
    this->r = sqrt(a*a+b*b);
    this->coss = a/this->r;
    this->sinn = b/this->r;
}

Complex::Complex(){
    this->a = 0;
    this->b = 0;
    this->r = sqrt(a*a+b*b);
    this->coss = a/this->r;
    this->sinn = b/this->r;
}


string Complex::print(){
    return to_string(this->coss) + " + i" + to_string(this->sinn);
}

Complex Complex::operator*(Complex complex){
    double real = this->r*complex.r*cos(this->coss+complex.coss);
    double imag = r*complex.r*sin(this->sinn+complex.sinn);
    return Complex(real,imag);
}


Complex Complex::operator-(Complex complex){
    double real = this->r*coss - complex.r*complex.coss;
    double imag = this->r*sinn - complex.r*complex.sinn;
    return Complex(real,imag);
}

Complex Complex::operator+(Complex complex){
    double real = this->r*coss + complex.r*complex.coss;
    double imag = this->r*sinn + complex.r*complex.sinn;
    return Complex(real,imag);
}

bool Complex::operator=(Complex complex){
    if (this->r==complex.r){
        return true;
    }
    return false;
}

bool Complex::operator>(Complex complex){
    if (this->r>complex.r){
        return true;
    }
    return false;
}

bool Complex::operator<(Complex complex){
    if (this->r<complex.r){
        return true;
    }
    return false;
}
