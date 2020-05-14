#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <QObject>
#include "estate.h"

class ApartmentCalc : public QObject{
    Q_OBJECT
public:
    explicit ApartmentCalc(QObject *parent = nullptr);
    static int getCost(Estate* value); // статическая функция, которая расчитывает и возвращает стоимость страхового взноса для жилья типа Апартаменты
signals:
};

#endif // APARTMENTCALC_H
