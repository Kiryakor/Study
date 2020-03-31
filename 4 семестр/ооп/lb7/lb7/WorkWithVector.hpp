//
//  WorkWithVector.hpp
//  lb7
//
//  Created by Кирилл on 31.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#ifndef WorkWithVector_hpp
#define WorkWithVector_hpp

#include <iostream>
#include <vector>

using namespace std;

class WorkWithVector{
private:
    int randomElement(int start,int finish);
public:
    void printData(vector<int> data);
    vector<int> randData(vector<int> data,int min,int max);
    vector<int> copy(vector<int> data);
    vector<int> mix(vector<int> data);
    float meanValue(vector<int> data);
    vector<int> vectorMultiplication(vector<int> first,vector<int> second);
    vector<int> powVector(vector<int> data);
};

#endif /* WorkWithVector_hpp */
