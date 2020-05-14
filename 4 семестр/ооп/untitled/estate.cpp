#include "estate.h"
#include<iostream>
#include<string>

Estate::Estate(QObject *parent) : QObject(parent){}

//конструктор по умолчанию
Estate::Estate(){
    this->age = 0;
    this->area = 0;
    this->residents = 0;
    this->months = 0;
    this->type = ECONOM;
    this->owner = "";
}

//конструктор с параметрами
Estate::Estate(int age,int area,int residents,int months,EstateType type,QString owner){
    this->age = age;
    this->area = area;
    this->residents = residents;
    this->months = months;
    this->type = type;
    this->owner = owner;
}

//функция возврата возраста
int Estate::getAge(){
    return  age;
}

//функция возврата площади
int Estate::getArea(){
    return  area;
}

//функция кол-ва жильцов
int Estate::getResidents(){
    return  residents;
}

//функция кол-ва месяцев
int Estate::getMonths(){
    return  months;
}

//функция возврата имени
QString Estate::getOwner(){
    return  owner;
}

//функция возврата типа жилья
Estate::EstateType Estate::getType(){
    return  type;
}

