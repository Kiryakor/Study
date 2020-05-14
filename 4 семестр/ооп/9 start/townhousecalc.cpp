#include "townhousecalc.h"

townhousecalc::townhousecalc(QWidget *parent) : QWidget(parent){}

//функция расчета стоимости жилья
//420 - коэффициент для данного типа жилья
int townhousecalc::getCost(Estate *value){
    return  value->getArea() * value->getMonths() * 420;
}
