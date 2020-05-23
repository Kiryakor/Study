//
//  main.cpp
//  mt3
//
//  Created by Кирилл on 23.05.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main() {
//}

#include <regex>
#include <iostream>
#include <sstream>
#include <map>
#include <string>

using namespace std;
struct Node{
    char symb;
    Node *Next;
};
class Stack{
    Node *Head;
    public: Stack() :Head(NULL) {};
    void Show();
    void Creat(char symb);
    void Del();
    char Ret();
};

void Stack::Creat(char symb){
    Node *temp = new Node;
    temp->symb = symb;
    temp->Next = Head;
    Head = temp;
}

char Stack::Ret(){
    char ret;
    Node *temp = Head;
    ret = Head->symb;
    return ret;
}

void Stack::Show(){
    Node *temp = Head;
    while (temp != NULL){
        cout << temp->symb << " ";
        temp = temp->Next;
    }
    cout << "\n";
}

void Stack::Del(){
    Node *temp = Head;
    Head = temp->Next;
    delete temp;
}


void LL1(string str3, int array[14][8], Stack st){
    int el = 0, x = 0, y = 0;
    st.Creat('$');
    st.Creat('D');
    while (el < str3.size()) {
        if (str3[el] == 'x'){
            y = 0;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T') {
                x = 3;
            }else if (st.Ret() == 'H') {
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() ==  'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*') {
                x = 10;
            }else if (st.Ret() == '('){
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '5'){
            y = 1;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '6'){
            y = 2;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '+'){
            y = 3;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '*'){
            y = 4;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '('){
            y = 5;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == ')'){
            y = 6;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (str3[el] == '$'){
            y = 7;
            if (st.Ret() == 'S'){
                x = 0;
            }else if (st.Ret() == 'E') {
                x = 1;
            }else if (st.Ret() == 'Z') {
                x = 2;
            }else if (st.Ret() == 'T'){
                x = 3;
            }else if (st.Ret() == 'H'){
                x = 4;
            }else if (st.Ret() == 'F'){
                x = 5;
            }else if (st.Ret() == 'x'){
                x = 6;
            }else if (st.Ret() == '5'){
                x = 7;
            }else if (st.Ret() == '6') {
                x = 8;
            }else if (st.Ret() == '+'){
                x = 9;
            }else if (st.Ret() == '*'){
                x = 10;
            }else if (st.Ret() == '(') {
                x = 11;
            }else if (st.Ret() == ')'){
                x = 12;
            }else if (st.Ret() == '$'){
                x = 13;
            }
        }
        if (array[x][y] == 0){
            cout << "Ошибка. Неподходящие слово" << endl;
            break;
        }else if (array[x][y] == 1){
            cout << "1" << endl;
            st.Del();
            st.Creat('E');
        }else if (array[x][y] == 2){
            cout << "2" << endl;
            st.Del();
            st.Creat('Z');
            st.Creat('T');
        }else if (array[x][y] == 3){
            cout << "3" << endl;
            st.Del();
            st.Creat('Z');
            st.Creat('T');
             st.Creat('+');
        }else if (array[x][y] == 4){
            cout << "4" << endl;
            st.Del();
            st.Creat('H');
            st.Creat('F');
        }else if (array[x][y] == 5){
            cout << "5" << endl;
            st.Del();
            st.Creat('H');
            st.Creat('F');
            st.Creat('*');
        }else if (array[x][y] == 6){
            cout << "6" << endl;
            st.Del();
            st.Creat('x');
        }else if (array[x][y] == 7){
            cout << "7" << endl;
            st.Del();
            st.Creat('5');
        }else if (array[x][y] == 8){
            cout << "8" << endl;
            st.Del();
            st.Creat('6');
        }else if (array[x][y] == 9){
            cout << "9" << endl;
            st.Del();
            st.Creat(')');
            st.Creat('E');
            st.Creat('(');
        }else if (array[x][y] == 10){
            cout << "10" << endl;
            st.Del();
        }
        else if (array[x][y] == 11){
            cout << "11" << endl;
            st.Del();
        }else if (array[x][y] == 88){
            st.Del();
            el++;
        }else if (array[x][y] == 100){
            st.Del();
            el++;
        }
    }
}

string Ans(string polynomial) {
    string s = polynomial;
    int z1 = 0;
    int z2 = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '('){
            z1++;
        }else if (s[i] == ')'){
            z2++;
        }
    }
    while (z1 > 0){
        s.erase(s.find('('), 1);
        z1--;
    }
    while (z2 > 0){
        s.erase(s.find(')'), 1);
        z2--;
    }
    map<int, int> poly;
    map<int, int> dxpoly;
    if (polynomial[0] != '-')
        s = '+' + s;
    const regex r("([+|-]\\d+)([\\*]x([\\^](\\d+))?)?");
    const regex rr("([+|-])x");
    const string fmt("$011*x");
    s = regex_replace(s, rr, fmt);
    for (sregex_iterator i(s.begin(), s.end(), r), end; i != end; ++i) {
        if ((*i)[2] == "") {
            int an = atoi((*i)[1].str().c_str());
            poly[0] += an;
        }else if ((*i)[2] == "*x") {
            int an = atoi((*i)[1].str().c_str());
            poly[1] += an;
        }else {
            int an = atoi((*i)[1].str().c_str());
            int xn = atoi((*i)[4].str().c_str());
            poly[xn] += an;
        }
    }
    for (auto it = poly.begin(); it != poly.end(); ++it) {
        dxpoly[it->first - 1] = it->second * it->first;
    }
    stringstream ss;
    for (auto it = dxpoly.rbegin(); it != dxpoly.rend(); ++it) {
        if (it->first < 0)
            continue;
        if (it->first == 0) {
            ss << showpos << it->second;
        }else if (it->first == 1) {
            if (abs(it->second) == 1){
                ss << (it->second > 0 ? "+x" : "-x");
            }else{
                ss << showpos << it->second << "*x";
            }
        }else {
            if (abs(it->second) == 1)
                ss << (it->second > 0 ? "+x" : "-x") << "^" << noshowpos << it->first;
            else ss << showpos << it->second << "*x^" << noshowpos << it->first; }
    }
    string result = ss.str();
    if (result.size() == 0)
        return "0";
    if (result[0] == '+')
        return result.substr(1);
    
    return result;
}

int main(){
    string str1, str2 = "$", str3;
    Stack st;
    int a, flag = 0;
    int array[14][8] = {
        { 1, 1, 1, 0, 0, 1, 0, 0 },
        { 2, 2, 2, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 3, 0, 0, 10, 10 },
        { 4, 4, 4, 0, 0, 4, 0, 0 },
        { 0, 0, 0, 11, 5, 0, 11, 11},
        { 6, 7, 8, 0, 0, 9, 0, 0 },
        { 88, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 88, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 88, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 88, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 88, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 88, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 88, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 100 }
    };
    cout << "Введите строку: ";
    cin >> str1;
    for (a = 0; a <= (str1.size() - 1); a++) {
        if ((str1[a] == 'x') || (str1[a] == '5') || (str1[a] == '6') || (str1[a] == '*') || (str1[a] == '+') || (str1[a] == '(') || (str1[a] == ')')){
            flag = 0;
        }else{
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "right" << endl;
        str3 = str1 + str2;
        LL1(str3, array, st);
        str3 = Ans(str1);
        cout << "\n" << "Результат = " << str3 << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}
