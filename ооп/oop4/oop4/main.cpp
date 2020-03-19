//
//  main.cpp
//  oop4
//
//  Created by Кирилл on 11.03.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Home{
protected:
    string name;
    float area;
    int cost;
    int peopleCount;
public:
    Home(string name,float area,int cost,int peopleCount){
        this->name = name;
        this->area = area;
        this->cost = cost;
        this->peopleCount = peopleCount;
    }
    
    Home(){
        this->name = "";
        this->area = 0;
        this->cost = 0;
        this->peopleCount = 0;
    }
    
    virtual void print(){
        cout << "название " << name << endl;
        cout << "общая площадь " << area << endl;
        cout << "базовая стоимость проживания человека в сутки " << cost << endl;
        cout << "количество жильцов " << peopleCount << endl;
    }
};

class House: public Home{
private:
    string material;
    string privateOrRent;
public:
    void print() override{
        cout << "yes" << endl;
    }
    House(string name,float area,int cost,int peopleCount,string material,string privateOrRent){
        this->name = name;
        this->area = area;
        this->cost = cost;
        this->peopleCount = peopleCount;
        this->material = material;
        this->privateOrRent = material;
    }
    float finalCost(){
        return cost*peopleCount;
    }
};

class Cottage: public Home{
private:
    float areaPlot;
    int countFloor;
public:
    Cottage(string name,float area,int cost,int peopleCount,int countFloor,float areaPlot){
        this->name = name;
        this->area = area;
        this->cost = cost;
        this->peopleCount = peopleCount;
        this->countFloor = countFloor;
        this->areaPlot = areaPlot;
    }
    float finalCost(){
        return peopleCount*cost;
    }
    void print() override{
        cout << "yes" << endl;
    }
};

class Hostel: public Home{
private:
public:
    Hostel(string name,float area,int cost,int peopleCount){
        this->name = name;
        this->area = area;
        this->cost = cost;
        this->peopleCount = peopleCount;
    }
    Hostel(){}
    float finalCost(){
        return peopleCount*cost;
    }
    void print() override{
        cout << "yes" << endl;
    }
};

int main() {
    House house("1",1,1,1,"string material","string privateOrRent");
    house.print();
    return 0;
}
