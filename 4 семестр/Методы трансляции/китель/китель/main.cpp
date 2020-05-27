#include <iostream>
#include <string>
#include <vector>

using namespace std;

string gramm[] = { "Blanket", "E","TZ","+TZ","FH","*FH","2","3","4","","" }; // грамматика

string table_left = "SEZTHF234+*#"; // строки таблицы (терминалы + нетерминалы + символ конца строки)

string table_top = "234+*#"; // столбцы таблицы (терминалы + символ конца строки)

int table[12][6] =

{//-2 - ошибка; -1 - выброс; 0 - допуск; с 1 до 10 - номера строк ПП, где происходит замена символа левой части на правую часть

{ 1, 1, 1, -2, -2, -2 },

{ 2, 2, 2, -2, -2, -2 },

{ -2, -2, -2, 3, -2, 9 },

{ 4, 4, 4, -2, -2, -2 },

{ -2, -2, -2, 10, 5, 10 },

{ 6, 7, 8, -2, -2, -2 },

{ -1, -2, -2, -2, -2, -2 },

{ -2, -1, -2, -2, -2, -2 },

{ -2, -2, -1, -2, -2, -2 },

{ -2, -2, -2, -1, -2, -2 },

{ -2, -2, -2, -2, -1, -2 },

{ -2, -2, -2, -2, -2, 0 }

};

vector<int> stack_digit; //стек символов

vector<char> stack_operation; //стек операций

bool check(string str)

{

string stack = "#S";

str += '#';

//добавление аксиомы и символа конца строки

for (int i = 1; !str.empty(); i++)

{

char symb = str.front();

char stack_state = stack.back();

int index_top = table_top.find(symb);

int index_left = table_left.find(stack_state);

if (index_top == std::string::npos)

return false;

int command = table[index_left][index_top];

switch (command)

{

case 0:

return true;

case -2:
        return false;

        case -1:

        {

        if (symb == '2' || symb == '3' || symb == '4')

        stack_digit.push_back(symb - '0');

        if (symb == '*' || symb == '+') stack_operation.push_back(symb);

        str.erase(0, 1);

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

        int Ans()

        {

        int c = 0;

        int s = stack_operation.size();

        for (int i = 0; i < s; )

        {

        if (stack_operation[i] == '*')

        {

        stack_digit[i] = stack_digit[i] * stack_digit[i + 1];

        stack_digit.erase(stack_digit.begin() + i + 1);

        stack_operation.erase(stack_operation.begin() + i);

        i = 0;

        s = stack_operation.size();

        }

        else

        i++;

        }

        cout << "\nОтвет: ";

        for (int i = 0; i < stack_digit.size(); i++)

        c += stack_digit[i];

        return c;

        }

        int main()

        {

        setlocale(LC_ALL, "rus");

        while (true)

        {

        string str;

        cout << "Введите выражение: \t"; cin >> str;

        if (check(str))

        cout << "Выражение соответствует грамматике.\n";

        else

        cout << "\nНекорректный ввод!\n";

        cout << "\nЦифры: ";

        for (int i = 0; i < stack_digit.size(); i++) {

        cout << stack_digit[i] << " ";

        }

        cout << "\nОперации: ";

        for (int i = 0; i < stack_operation.size(); i++) {

        cout << stack_operation[i] << " ";

        }

        cout << Ans() << endl;

        stack_digit.clear();

        stack_operation.clear();

        cout << "\n";

        }

        return 0;

        }
