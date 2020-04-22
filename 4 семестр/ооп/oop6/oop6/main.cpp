//
//  main.cpp
//  oop6
//
//  Created by Кирилл on 22.04.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class My_Error {
private:
    string message;
public:
    My_Error();
    My_Error(string message);
    string getMesage();
};

My_Error::My_Error(){
    this->message = "Ошибка";
}

My_Error::My_Error(string message){
    this->message = message;
}

string My_Error::getMesage(){
    return message;
}

class MyVector{
private:
    vector<int> data;
    const int dataSize = 12;
public:
    MyVector();
    void cinData();
    void print();
    int oddIndex(); //сумму элементов массива с нечетными номерами
    int sumFLElement(); //сумму элементов массива, расположенных между первым и последним отрицательными элементами
    void compression(); //Сжать массив, удалив из него все элементы, модуль которых не превышает единицу. Освободившиеся в конце массива элементы заполнить нулями
};

MyVector::MyVector(){}

void MyVector::cinData(){
    for (int i=0;i<dataSize;i++){
        int j;
        cout << "введите " << i << " элемент массива" << endl;
        cin >> j;
        data.push_back(j);
    }
}

void MyVector::compression(){
    vector<int> removeIndex;
    for (int i=0; i<dataSize; i++) {
        if (data[i] >= -1 && data[i] <= 1){
            removeIndex.push_back(i);
        }
    }
    
    for (int i=0;i<removeIndex.size();i++){
        data.erase(data.begin()+removeIndex[i]);
    }

    for (int i=0;i<removeIndex.size();i++){
        data.push_back(0);
    }
}

int MyVector::sumFLElement(){
    int firstElIndex = -1;
    int lastElIndex = -1;
    int sum = 0;
    
    for (int i=0; i<dataSize; i++) {
        if (data[i] < 0 && firstElIndex == -1){
            firstElIndex = i;
        }else if (data[i] < 0 && firstElIndex > -1){
            lastElIndex = i;
        }
    }
    
    if (lastElIndex == -1) {
        return sum;
    }else{
        for (int i=firstElIndex;i<lastElIndex;i++){
            sum += data[i];
        }
        return sum;
    }
}

int MyVector::oddIndex(){
    int sum = 0;
    for (int i=0;i<dataSize;i++){
        if (i % 2 == 0){
            sum += data[i];
        }
    }
    return sum;
}

void MyVector::print(){
    for (int i=0;i<dataSize;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    MyVector data;

    try {
        data.cinData();
    } catch (My_Error error){
        error = My_Error("Ошибка ввода данных");
        cout << error.getMesage() << endl;
    }
    data.print();
    
    
    try {
        cout << "сумма элементов массива с нечетными номерами " << data.oddIndex() << endl;
    } catch (My_Error error) {
        error = My_Error("Ошибка функции нахождения суммы элементов массива с нечетными номерами ");
        cout << error.getMesage() << endl;
    }
    
    
    try {
        cout << "сумма элементов массива, расположенных между первым и последним отрицательными элементами " << data.sumFLElement() << endl;
    } catch (My_Error error) {
        error = My_Error("Ошибка функции нахождения суммы элементов массива с нечетными номерами");
        cout << error.getMesage() << endl;
    }
    
    try {
        data.compression();
    } catch (My_Error error) {
        error = My_Error("Ошибка функции Сжать массив, удалив из него все элементы, модуль которых не превышает единицу. Освободившиеся в конце массива элементы заполнить нулями");
        cout << error.getMesage() << endl;
    }
    
    try {
        data.print();
    } catch (My_Error error) {
        error = My_Error("Ошибка");
        cout << error.getMesage() << endl;
    }
    
    return 0;
}
