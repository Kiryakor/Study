//
//  main.cpp
//  oop5
//
//  Created by Кирилл on 19/03/2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>

using namespace std;

class B1{
private:
    int b1;
public:
    B1(int b1){
        this->b1 = b1;
        cout << "Работает конструктор B1: параметр = " << b1 << endl;
    };
    ~B1(){
        cout << "~B1 сработал" << endl;
    };
    void showB1(){
        cout << "B1 =  " << b1 << endl;
    };
};

class B2{
private:
    int b2;
public:
    B2(int b2){
        this->b2 = b2;
        cout << "Работает конструктор B2: параметр = " << b2 << endl;
    };
    ~B2(){
       cout << "~B2 сработал" << endl;
    };
    void showB2(){
        cout << "B2 =  " << b2 << endl;
    };
};

class D1:virtual public B1{
private:
    int d1;
public:
    D1(int b1,int d1) : B1(b1){
        this->d1 = d1;
        cout << "Работает конструктор D1: параметр = " << d1 << endl;
    };
    ~D1(){
        cout << "~D1 сработал" << endl;
    };
    void showD1(){
        cout << "D2 =  " << d1 << endl;
        showB1();
    };
};

class D2:virtual private B1{
private:
    int d2;
public:
    D2(int b1,int d2) : B1(b1){
        this->d2 = d2;
         cout << "Работает конструктор D2: параметр = " << d2 << endl;
    };
    ~D2(){
        cout << "~D2 сработал" << endl;
    };
    void showD2(){
        cout << "D2 =  " << d2 << endl;
        showB1();
    };
};

class D4:public D1,public D2, private B2{
private:
    int d4;
public:
    D4(int b1,int b2,int d1,int d2,int d4) : D2(b1,d2),B2(b2),D1(b1,d1),B1(b1){
        this->d4 = d4;
         cout << "Работает конструктор D3: параметр = " << d4 << endl;
    };
    ~D4(){
        cout << "~D2 сработал" << endl;
    };
    void showD4(){
        cout << "D4 =  " << d4 << endl;
        showD2();
        showD1();
        showB2();
    };
};

int main() {
    D4 temp(1, 2, 3, 4, 5);
    temp.showD4();
}
