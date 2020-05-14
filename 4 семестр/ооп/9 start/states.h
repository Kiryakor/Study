#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>

//класс для хранения информации о предыдущих запросах
class States : public QObject{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo(); //функция для работы с actualData
    bool hasStates(); //функция для проверки коллекции на наличие элементов
    Estate *getActualData(); //функция возвращает последний элемент коллекции
    void add(Estate *value); //функция добавляет элемент в коллекцию
    void notifyObservers();
private:
    QList<Estate *> array; //объявление коллекции, которая может хранить элементы класса Estate
    Estate *actualData; // последния данные
};

#endif // STATES_H
