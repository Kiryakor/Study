//
//  main.cpp
//  finalMT
//
//  Created by Кирилл on 28.05.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

//MARK: разобраться с X и числом в конце
//5*(6+x*x*x+5)
//x
using namespace std;

string gramm[] = { "Blanket", "E","TZ","+TZ","FH","*FH","x","5","6","(E)","","" }; // грамматика (вообще "" это степень
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

//MARK: Сheck
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
        switch (command){
            case 0:
                return false; // ошибка
            case 100:
                return true; // верное
            case 88:{
                //тут надо действия делать
                if (symb == '5' || symb == '6')
                    stack_digit.push_back(symb - '0');
                if (symb == 'x') //вместо x добавляем x
                    stack_digit.push_back(-1);
                if (symb == '*' || symb == '+' || symb == '(' || symb == ')')
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

//MARK: Преобразования Name
pair<vector<int>, vector<char>> name(vector<int> digit,vector<char> operation){
    unsigned long int size = operation.size();
    for (auto index=0;index<size;index++){
        if (digit[index] != -1){ //!= x
            if (operation[index] == '+'){
                digit.erase(digit.begin() + index);
                operation.erase(operation.begin() + index);
                size = operation.size();
                index = -1;
            }else if (operation[index] == '*' && digit[index+1] != -1){
                digit[index] = digit[index] * digit[index + 1];
                digit.erase(digit.begin() + index + 1);
                operation.erase(operation.begin() + index);
                index = -1;
                size = operation.size();
            }
            if (index == size - 1){
                break;
            }
        }else{ //==x
            if (digit[index] == -1 && operation[index] == '^'){
                index++;
                continue;
            }else{
                //MARK:  что-то не так с размером
                int count = 1;
                for(auto j=index;j<size;j++){
                    if (digit[j] == -1 && operation[j] == '*' && digit[j+1] == -1){
                        count++;
                        if (j == size - 1){
                            int count2 = count - 1;
                            digit.erase(digit.begin() + index + count2);
                            while (count2>0) {
                                digit.erase(digit.begin() + index + count2 - 1);
                                operation.erase(operation.begin() + index + count2 - 1);
                                count2--;
                            }
                            digit.insert(digit.begin() + index, count);
                            operation.insert(operation.begin() + index, '*');
                            digit.insert(digit.begin() + index + 1, -1);
                            operation.insert(operation.begin() + index + 1, '^');
                            digit.insert(digit.begin() + index + 2, count - 1);
                            //index = -1;
                            size = operation.size();
                            break;
                        }
                    }else{
                        int count2 = count - 1;
                        digit.erase(digit.begin() + index + count2);
                        while (count2!=0) {
                            digit.erase(digit.begin() + index + count2 - 1);
                            operation.erase(operation.begin() + index + count2 - 1);
                            count2--;
                        }
                        digit.insert(digit.begin() + index, count);
                        operation.insert(operation.begin() + index, '*');
                        digit.insert(digit.begin() + index + 1, -1);
                        operation.insert(operation.begin() + index + 1, '^');
                        digit.insert(digit.begin() + index + 2, count - 1);
                        size = operation.size();
                        index = -1;
                        break;
                    }
                }
            }
        }
    }
    return pair<vector<int>,vector<char>>(digit,operation);
}

//MARK: Ans
string Ans(){
    unsigned long int s = stack_operation.size();
    bool check = false;
    vector<int> stackDigit; //стек символов
    vector<char> stackOperation; //стек операций
    int index = 0;
    //избавляемся от скобок
    for (int i=0;i<s;i++){
        if (stack_operation[i] == '('){
            index = i;
            check = true;
            stackDigit.clear();
            stackOperation.clear();
            stackDigit.push_back(stack_digit[i]);
        }else if (stack_operation[i] == ')'){
            //получаем пару значение
            auto p = name(stackDigit,stackOperation);
            //удаляем все значения из скобок в исходном векторе
            stack_digit.erase(stack_digit.begin()+index,stack_digit.begin()+i);
            stack_operation.erase(stack_operation.begin()+index,stack_operation.begin()+i+1);
            //добавляем преобразованные данные
            for (int i=0; i<p.first.size(); i++)
                stack_digit.insert(stack_digit.begin()+index+i, p.first[i]);
            for (int i=0; i<p.second.size(); i++)
                stack_operation.insert(stack_operation.begin()+index+i, p.second[i]);
            i = -1;
            s = stack_operation.size();
            check = false;
        }else if (check){
            stackDigit.push_back(stack_digit[i]);
            stackOperation.push_back(stack_operation[i]);
        }
    }
    auto p = name(stack_digit,stack_operation);
    stack_digit = p.first;
    stack_operation = p.second;
    
//MARK: Convert data from Vector to String
    string c = "";
    string xLine = "x";
    for (int i=0;i<stack_operation.size();i++){
        if (stack_digit[i] == -1)
            c += xLine;
        else
            c += to_string(stack_digit[i]);
        c += stack_operation[i]; //в теории тут можно проверку добавить на digite i+1 != числу
    }
    c += to_string(stack_digit[stack_digit.size()-1]);
    return c;
}

//MARK:Main
int main(){
    while (true){
        string str;
        cout << "Введите выражение: \t";
        cin >> str;
        
        if (check(str)){
            cout << "Выражение соответствует грамматике.\n";
            cout << Ans() << endl;
        }else{
            cout << "Некорректный ввод!\n";
        }
        
        stack_digit.clear();
        stack_operation.clear();
        cout << "\n";
    }
    return 0;
}

