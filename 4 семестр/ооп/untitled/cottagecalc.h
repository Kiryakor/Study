#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <QQuickItem>
#include "estate.h"

class cottagecalc : public QQuickItem{
    Q_OBJECT
public:
    cottagecalc(); //конструктор класса ApartmentCalc
    static int getCost(Estate* value); // статическая функция, которая расчитывает и возвращает стоимость страхового взноса для жилья типа Коттедж
signals:

};

#endif // COTTAGECALC_H
