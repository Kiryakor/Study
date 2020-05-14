#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <QWidget>
#include <estate.h>

class townhousecalc : public QWidget{
    Q_OBJECT
public:
    explicit townhousecalc(QWidget *parent = nullptr);
    static int getCost(Estate* value); // статическая функция, которая расчитывает и возвращает стоимость страхового взноса для жилья типа ТаунХаус
signals:

};

#endif // TOWNHOUSECALC_H
