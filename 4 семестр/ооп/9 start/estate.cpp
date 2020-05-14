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
QString Estate::getAge(){
    return QString(age);
}

//функция возврата площади
QString Estate::getArea(){
    return  QString(area);
}

//функция кол-ва жильцов
QString Estate::getResidents(){
    return  QString(residents);
}

//функция кол-ва месяцев
QString Estate::getMonths(){
    return  QString(months);
}

//функция возврата имени
QString Estate::getOwner(){
    return  QString(owner);
}

//функция возврата типа жилья
QString Estate::getType(){
    return  QString(type);
}

