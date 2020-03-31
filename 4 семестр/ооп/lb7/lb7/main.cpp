//
//  main.cpp
//  lb7
//
//  Created by Кирилл on 31.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "WorkWithVector.hpp"
#include <vector>
#include <iostream>

using namespace std;

//m1=0, m2=15
// создать второй массив как копию первого
// перемешать случайным образом все элементы 2-го массива
// вычислить среднее значение всех элементов массива
// перемножить поэлементно два массива
// возвести в квадрат каждый элемент полученного массива

int main() {
    WorkWithVector workWithVector;
    vector<int> data;
    data = workWithVector.randData(data, 0, 15);
    cout << "Массив 1 заполненный случайныеми числами" << endl;
    workWithVector.printData(data);
    
    vector<int> data2 = workWithVector.copy(data);
    cout << endl << endl << "Массив 2  - копия массива 1" << endl;
    workWithVector.printData(data2);
    
    data2 = workWithVector.mix(data2);
    cout << endl << endl << "Среднее значение: " << workWithVector.meanValue(data);
    
    vector<int> data3 = workWithVector.vectorMultiplication(data, data2);
    cout << endl << endl << "перемножение 2-х массивов" << endl;
    workWithVector.printData(data3);
    
    data3 = workWithVector.powVector(data3);
    cout << endl << endl << "возвели каждый элемент в квадрат " << endl;
    workWithVector.printData(data3);
    cout << endl << endl;
}
