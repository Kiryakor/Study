#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include "estate.h"

class luxuriousapartmentcalc : public QObject{
    Q_OBJECT
public:
    explicit luxuriousapartmentcalc(QObject *parent = nullptr);
    static int getCost(Estate* value); // статическая функция, которая расчитывает и возвращает стоимость страхового взноса для жилья типа Люкс
signals:

};

#endif // LUXURIOUSAPARTMENTCALC_H
