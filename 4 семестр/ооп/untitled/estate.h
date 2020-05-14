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
    int getAge(); //функция для возврата значение age
    int getArea(); //функция для возврата значение area
    int getResidents(); //функция для возврата значение residents
    int getMonths(); //функция для возврата значение months
    EstateType getType(); //функция для возврата значение type
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
