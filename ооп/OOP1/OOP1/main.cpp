//
//  main.cpp
//  OOP1
//
//  Created by Кирилл on 12.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include "Date.hpp"

using namespace std;

void readDate(int dateArr[]){
    cout << "Введите день рождения" << endl;
    cin >> dateArr[0];
    cout << "Введите месяц рождения" << endl;
    cin >> dateArr[1];
    cout << "Введите год рождения" << endl;
    cin >> dateArr[2];
}

void menu(){
    cout << "1 - ввести данные" << endl;
    cout << "2 - вывести данные" << endl;
    cout << "3 - проверить дату рождения" << endl;
    cout << "4 - выход" << endl;
}

int main() {
    Date date;
    int dateArr[3];
    
    int choose = -1;
    while (choose!=4) {
        menu();
        cin >> choose;
        switch (choose) {
            case 1:
                readDate(dateArr);
                date.get(dateArr);
                break;
            case 2:
                date.print();
                break;
            case 3:
                date.check();
            case 4:
                break;
            default:
                cout << "try again" << endl;
                break;
        }
    }
    return 0;
}
