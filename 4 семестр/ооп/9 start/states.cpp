#include "states.h"
#include "widget.h"

States::States(QObject *parent) : QObject(parent) {
    actualData = nullptr;
}

States::~States() {
    if(actualData){
        delete actualData;
        actualData = nullptr;
    }
    qDeleteAll(array);
    array.clear();
}

//проверка коллекции на пустоту
bool States::hasStates(){
    return !array.isEmpty();
}

//возврат актуального значение
Estate* States::getActualData(){
    return actualData;
}

//добавление данных в коллекцию
void States::add(Estate *value){
    array.append(value);
}

//обновление актуального значения
void States::undo(){
    if (hasStates()){
        actualData = NULL;
    }else{
        actualData = array.last();
        array.removeLast();
    }
    emit notifyObservers();
}

void States::notifyObservers(){
    //Widget.update();
}
