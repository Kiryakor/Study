//
//  main.cpp
//  oop3
//
//  Created by Кирилл on 26.02.2020.
//  Copyright © 2020 Кирилл. All rights reserved.
//

#include <iostream>
#include <string>
#include "Complex.hpp"

using namespace std;

int main() {
    Complex complex(2,3);
    Complex complex2(1,2);
    int choose;
    bool check = true;
    while (check) {
        cin >> choose;
        switch (choose) {
            case 1:{
                cout << "(" << complex.print() << ") - (" << complex2.print() << ") = " ;
                Complex complex3 = complex - complex2;
                cout << "(" <<  complex3.print() << ")"<< endl;
                break;
            }
            case 2:{
                cout << "(" << complex.print() << ") + (" << complex2.print() << ") = " ;
                Complex complex3 = complex + complex2;
                cout << "(" <<  complex3.print() << ")"<< endl;
                break;
            }
            case 3:{
                cout << "(" << complex.print() << ") / (" << complex2.print() << ") = " ;
                Complex complex3 = complex / complex2;
                cout << "(" <<  complex3.print() << ")"<< endl;
                break;
            }
            case 4:{
                cout << "(" << complex.print() << ") * (" << complex2.print() << ") = " ;
                Complex complex3 = complex * complex2;
                cout << "(" <<  complex3.print() << ")"<< endl;
                break;
            }
            case 5:{
                cout << "равенство: ";
                cout << to_string(complex = complex2) << endl;
                break;
            }
            case 6:{
                cout << "меньше: ";
                cout << to_string(complex < complex2) << endl;
                break;
            }
            case 7:{
                cout << "больше: ";
                cout << to_string(complex > complex2) << endl;
                break;
            }
            case 8:{
                cout << "вывод: " <<complex.print() << endl;
                break;
            }
            case 9:{
                string line;
                cin >> line;
                complex.fromString(line);
                cout << complex.print() << endl;
                break;
            }
            default:{
                check = false;
            }
        }
    }
    return 0;
}
