#include "widget.h"
#include "ui_widget.h"
#include "estate.h"
#include "states.h"

Widget::Widget(QWidget *parent) : QWidget(parent),ui(new Ui::Widget), info(this){
    ui->setupUi(this);
    ui->btnUndo->setEnabled(false);

    // регистрация слушателя
    connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
    connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

Widget::~Widget() {
    delete ui;
}

// public slots
void Widget::update() {
    auto value = info.getActualData();
    if(value != nullptr){
        fillForm(value);
    }
    // update btnUndo state
    ui->btnUndo->setEnabled(info.hasStates());
    // setting value to NULL
    value = nullptr;
}

// private slots
void Widget::btnCalcPressed() {
    auto value = processForm();
    showCost(value);
    info.add(value);
    ui->btnUndo->setEnabled(true);
    // setting value to NULL
    value = nullptr;
}

void Widget::btnUndoPressed() {
    info.undo();
}

// private
Estate *Widget::processForm() {
    return new Estate();
}

Widget::fillForm(Estate *value) {
    QString ageString = value->getAge();
    QString areaString = value->getArea();
    QString residentsString = value->getResidents();
    QString ownerString = value->getOwner();

    ui->age->setText(ageString);
    ui->area->setText(areaString);
    ui->residents->setText(residentsString);
    ui->owner->setText(ownerString);
}

Widget::showCost(Estate *value) {
}
