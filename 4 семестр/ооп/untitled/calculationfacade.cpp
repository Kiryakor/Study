#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent){
}

int CalculationFacade::getCost(Estate *value) {
    int cost;
    switch (value->getType()) {
    case Estate::EstateType::ECONOM:
       cost = ApartmentCalc::getCost(value); //произходит вызов статической функции класса ApartmentCalc, если value->getType() == ECONOM
       break;
    case Estate::EstateType::LUXURIOUS:
        cost = luxuriousapartmentcalc::getCost(value); //произходит вызов статической функции класса luxuriousapartmentcalc, если value->getType() == LUXURIOUS
        break;
    case Estate::EstateType::TOWN_HOUSE:
        cost = townhousecalc::getCost(value); //произходит вызов статической функции класса townhousecalc, если value->getType() == TOWN_HOUSE
        break;
    case Estate::EstateType::COTTAGE:
        cost = cottagecalc::getCost(value); //произходит вызов статической функции класса cottagecalc, если value->getType() == COTTAGE
        break;
    default:
        cost = -1;
        break;
    }
    return cost;
}
