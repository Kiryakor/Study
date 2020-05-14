#include "apartmentcalc.h"

ApartmentCalc::ApartmentCalc(QObject *parent) : QObject(parent){} //конструктор класса ApartmentCalc

//расчет стоимости
//30 - кол-во дней в месяце
//320 - коэффициент для данного типа жилья
int ApartmentCalc::getCost(Estate *value){
    return value->getArea() * value->getMonths() * 30 * 320;
}
