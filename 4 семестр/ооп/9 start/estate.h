#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject{
    Q_OBJECT
public:
    //перечисление недвижимости в предметной области
    enum EstateType {
            ECONOM,
            LUXURIOUS,
            TOWN_HOUSE,
            COTTAGE
    };
    Estate(); //конструктор по умолчанию
    Estate(int age,int area,int residents,int months,EstateType type,QString owner); // конструктор с параметрами
    QString getAge(); //функция для возврата значение age
    QString getArea(); //функция для возврата значение area
    QString getResidents(); //функция для возврата значение residents
    QString getMonths(); //функция для возврата значение months
    QString getType(); //функция для возврата значение type
    QString getOwner(); //функция для возврата значение owner
    explicit Estate(QObject *parent = nullptr);
    EstateType getType() const;
private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;
signals:
};

#endif // ESTATE_H
