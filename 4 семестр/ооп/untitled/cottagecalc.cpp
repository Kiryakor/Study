#include "cottagecalc.h"

cottagecalc::cottagecalc(){}

//функция для расчета стоимости
//20 - коэффициент для данного типа жилья
int cottagecalc::getCost(Estate *value){
    return  value->getArea() * value->getMonths() * value->getResidents() * 20;
}
