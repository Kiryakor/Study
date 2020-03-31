//
//  WorkWithVector.cpp
//  lb7
//
//  Created by Кирилл on 31.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include "WorkWithVector.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>

int WorkWithVector::randomElement(int start, int finish){
    return rand() % (start+finish) - start;
}

void WorkWithVector::printData(vector<int> data){
    for (int i=0;i<data.size();i++) {
        cout << data[i] << " ";
    }
}

vector<int> WorkWithVector::randData(vector<int> data, int min, int max){
    srand(time(NULL));
    for (int i=0;i<10;i++){
        data.push_back(randomElement(min, max));
    }
    return data;
}

vector<int> WorkWithVector::copy(vector<int> data){
    vector<int> copyData;
    for (int i=0;i<data.size();i++){
        copyData.push_back(data[i]);
    }
    return copyData;
}

vector<int> WorkWithVector::mix(vector<int> data){
    for (int i=0;i<data.size();i++) {
        swap(data[i],data[rand()%data.size()]);
    }
    return data;
}

float WorkWithVector::meanValue(vector<int> data){
    int sum = 0;
    for (int i=0;i<data.size();i++){
        sum += data[i];
    }
    return sum/data.size();
}

vector<int> WorkWithVector::vectorMultiplication(vector<int> first,vector<int> second){
    vector<int> returnData;
    for (int i=0;i<second.size();i++){
        returnData.push_back(first[i]*second[i]);
    }
    return returnData;
}

vector<int> WorkWithVector::powVector(vector<int> data){
    for (int i=0;i<data.size();i++){
        data[i] = pow(data[i], 2);
    }
    return data;
}
