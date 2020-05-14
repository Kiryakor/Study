#include "luxuriousapartmentcalc.h"

luxuriousapartmentcalc::luxuriousapartmentcalc(QObject *parent) : QObject(parent){}

//функция для расчета стоимости
//500 - коэффициент для данного типа жилья
int luxuriousapartmentcalc::getCost(Estate *value){
    return  value->getArea() * value->getMonths() * 500;
}
