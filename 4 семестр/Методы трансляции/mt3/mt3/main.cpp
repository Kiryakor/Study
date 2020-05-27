//
//  main.cpp
//  mt3
//
//  Created by Кирилл on 23.05.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string gramm[] = { "Blanket", "E","TZ","+TZ","FH","*FH","x","5","6","(E)","^","^" }; // грамматика
string table_left = "SEZTHFx56+*()#"; // строки таблицы (терминалы + нетерминалы + символ конца строки)
string table_top = "x56+*()#"; // столбцы таблицы (терминалы + символ конца строки)

int table[14][8] = {
    // x 5 6 + * ( ) #
    { 1, 1, 1, 0, 0, 1, 0, 0 }, //S
    { 2, 2, 2, 0, 0, 2, 0, 0 }, //E
    { 0, 0, 0, 3, 0, 0, 10, 10 }, //Z
    { 4, 4, 4, 0, 0, 4, 0, 0 }, // T
    { 0, 0, 0, 11, 5, 0, 11, 11}, // H
    { 6, 7, 8, 0, 0, 9, 0, 0 }, // F
    { 88, 0, 0, 0, 0, 0, 0, 0 }, // x
    { 0, 88, 0, 0, 0, 0, 0, 0 }, // 5
    { 0, 0, 88, 0, 0, 0, 0, 0 }, // 6
    { 0, 0, 0, 88, 0, 0, 0, 0 }, // +
    { 0, 0, 0, 0, 88, 0, 0, 0 }, // *
    { 0, 0, 0, 0, 0, 88, 0, 0 }, // (
    { 0, 0, 0, 0, 0, 0, 88, 0 }, // )
    { 0, 0, 0, 0, 0, 0, 0, 100 }  // $
};

vector<int> stack_digit; //стек символов
vector<char> stack_operation; //стек операций

//MARK: под мою грамматику
//проверяем подходит ли слово под нашу грматику и заполяем наш стек операций и стек символов
bool check(string str){
    string stack = "#S";
    str += '#'; //добавление аксиомы и символа конца строки

    for (int i = 1; !str.empty(); i++){
        char symb = str.front(); // обращение к 1 элементу строки
        char stack_state = stack.back(); // обращение к последнему элементу строки
        unsigned long int index_top = table_top.find(symb);
        unsigned long int index_left = table_left.find(stack_state);
       
        if (index_top == string::npos) //проверка на несуществующую позицию
            return false;

        int command = table[index_left][index_top];
        cout << "command " << command << endl;
        cout << stack_state << endl;
        switch (command){
            case 0:
                return false; // ошибка
            case 100:
                return true; // верное
            case 88:{
                //тут надо действия делать
                //MARK: мб надо что-то с X сделать
                if (symb == '5' || symb == '6')
                    stack_digit.push_back(symb - '0');
                if (symb == '*' || symb == '+' || symb == 'x' || symb == '(' || symb == ')')
                    stack_operation.push_back(symb);
                str.erase(0, 1); // удаляем 0 элемент строки
                stack.pop_back();
                continue;
            }
        }
        
        string state = gramm[command];
        stack.pop_back();
        stack += string(state.rbegin(), state.rend());;
    }
    return false;
}

int Ans(){
    int c = 0;
    unsigned long int s = stack_operation.size();
    //сначала делаем умножение
    for (int i = 0; i < s; ){
        if (stack_operation[i] == '*'){
            stack_digit[i] = stack_digit[i] * stack_digit[i + 1];
            stack_digit.erase(stack_digit.begin() + i + 1);
            stack_operation.erase(stack_operation.begin() + i);
            i = 0;
            s = stack_operation.size();
        }else{
            i++;
        }
    }
    
    cout << "\nОтвет: ";
    //потом сумму
    for (int i = 0; i < stack_digit.size(); i++){
        c += stack_digit[i];
    }
    
    return c;
}

int main(){
    while (true){
        string str;
        cout << "Введите выражение: \t";
        cin >> str;
        if (check(str)){
            cout << "Выражение соответствует грамматике.\n";
        }else{
            cout << "\nНекорректный ввод!\n";
        }
        
        cout << "\nЦифры: ";
        for (int i = 0; i < stack_digit.size(); i++) {
            cout << stack_digit[i] << " ";
        }

        cout << "\nОперации: ";
        for (int i = 0; i < stack_operation.size(); i++) {
            cout << stack_operation[i] << " ";
        }

        //cout << Ans() << endl;
        stack_digit.clear();
        stack_operation.clear();
        cout << "\n";
    }
    return 0;
}
