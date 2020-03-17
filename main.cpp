#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

string const Href = "";

struct ansers{
    string anser;
    string auther;
    string category;
};

class RandomAnser{
private:
    vector<ansers> allAnser;
    
    void addAnser();
    void removeAnser();
    void editAnser();
    void randomAnser();
    void printCategoryList();
    void countAnser();
    void printAllAnser();
    void readData();
    void info();
    void saveData();
    void menu();
public:
    void start();
};

int main() {
    RandomAnser randomAnser;
    randomAnser.start();
    return 0;
}

void RandomAnser::addAnser(){
    ansers newElemet;
    bool check = true;
    cout << "Введите новый случайный ответ" << endl;
    cin >> newElemet.anser;
    for (int i=0;i<allAnser.size();i++){
        if (newElemet.anser == allAnser[i].anser){
            cout << "Такой ответ уже есть" << endl;
            check = false;
        }
    }
    if (check){
        cout << "Введите автора случайного ответа" << endl;
        cin >> newElemet.auther;
        cout << "Введите категорию" << endl;
        cin >> newElemet.category;
        
        for (int i=0;i<allAnser.size();i++){
            if (newElemet.category == allAnser[i].category){
                check = false;
                break;
            }
        }
        if (!check){
            allAnser.push_back(newElemet);
        }
    }
}

void RandomAnser::removeAnser(){
    string remove;
    bool check = true;
    cout << "Введите ответ, который хотите удалить" << endl;
    cin >> remove;
    for (int i=0;i<allAnser.size();i++){
        if (remove == allAnser[i].anser){
            allAnser.erase(allAnser.begin()+i);
            cout << "Ответ успешно удален" << endl;
            check = false;
        }
    }
    if (check){
        cout << "Не удалось найти такой ответ" << endl;
    }
}

void RandomAnser::editAnser(){
    string remove;
    bool check = false;
    int value;
    int index = -1;
    cout << "Введите ответ, поле которого хотите изменить " << endl;
    cin >> remove;
    for (int i=0;i<allAnser.size();i++){
        if (remove == allAnser[i].anser){
            check = true;
            index = i;
            break;
        }
    }
    if (check){
        cout << "Какое поле хотите изменить ?" << endl;
        cout << "1 - ответ" << endl;
        cout << "2 - автора" << endl;
        cout << "3 - категорию" << endl;
        cin >> value;
        if (value>0 && value<4){
            string newValue;
            cout << "Введите новое значение" << endl;
            cin >> newValue;
            switch (value) {
                case 1:
                    allAnser[index].anser = newValue;
                    break;
                case 2:
                    allAnser[index].auther = newValue;
                    break;
                case 3:
                    allAnser[index].category = newValue;
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        }else{
            cout << "error" << endl;
        }
    }else{
        cout << "Такого ответа нету" << endl;
    }
}

void RandomAnser::randomAnser(){
    srand(unsigned(time(0)));
    int randomIndex = rand() % allAnser.size();
    cout << allAnser[randomIndex].anser << endl;
}

void RandomAnser::printCategoryList(){
    cout << "Напишите категорию, ответы которой вы хотите увидеть ?" << endl;
    string line;
    cin >> line;
    bool check = false;
    for (int i=0;i<allAnser.size();i++){
        if(allAnser[i].category == line){
            cout << allAnser[i].category << endl;
            check = true;
        }
    }
    if (!check){
        cout << "По вашей категории ничего не найдено" << endl;
    }
}

void RandomAnser::countAnser(){
    cout << "В базе данных: " << allAnser.size()  << " ответов" << endl;
}

void RandomAnser::printAllAnser(){
    for (int i=0;i<allAnser.size();i++){
        cout << allAnser[i].anser << endl;
    }
}

void RandomAnser::info(){
    cout << "Приложение по генерации ответов" << endl;
    cout << "Разработчик - Денисенко Владислав" << endl;
}

void RandomAnser::readData(){
    ifstream file(Href);
    if (!file){
        cout << "файл не найден" << endl;
    }else{
        string data;
        while (getline(file,data)) {
            ansers readData;
            string line;
            int count = 0;
            for (int i=0;i<data.length();i++){
                if (data[i]==' '){
                    switch (count) {
                        case 0:
                            readData.anser = line;
                            break;
                        case 1:
                            readData.auther = line;
                            break;
                        case 2:
                            readData.category = line;
                            allAnser.push_back(readData);
                            break;
                        default:
                            break;
                    }
                    count++;
                    line = "";
                }else{
                    line+= data[i];
                }
            }
        }
        file.close();
    }
}

void RandomAnser::saveData(){
    ofstream file(Href);
    if (file.is_open()){
        for (int i=0;i<allAnser.size();i++){
            string line = allAnser[i].anser + " " + allAnser[i].auther + " " + allAnser[i].category;
            file << line << endl;
        }
        cout << "Данные успешно сохранены" << endl;
    }else{
        cout << "файл не найден" << endl;
    }
}

void RandomAnser::menu(){
    int choose = -1;
    while (choose!=10) {
        system("cls");
        cout << "Меню" << endl;
        cout << "1 - вывод списка всех ответов" << endl;
        cout << "2 - добавить новый ответ" << endl;
        cout << "3 - удалить выбранный ответ" << endl;
        cout << "4 - изменить поле какого-то ответа" << endl;
        cout << "5 - получить случайный ответ" << endl;
        cout << "6 - вывод всех ответов заданной категории" << endl;
        cout << "7 - сохранить данные в базе данных" << endl;
        cout << "8 - получить количество ответов в базе данных" << endl;
        cout << "9 - информация о программе" << endl;
        cout << "10 - выход" << endl;
        cin >> choose;
        system("cls");
        switch (choose) {
            case 1:
                printAllAnser();
                break;
            case 2:
                addAnser();
                break;
            case 3:
                removeAnser();
                break;
            case 4:
                editAnser();
                break;
            case 5:
                randomAnser();
                break;
            case 6:
                printCategoryList();
                break;
            case 7:
                saveData();
                break;
            case 8:
                countAnser();
                break;
            case 9:
                info();
                break;
            default:
                break;
        }
    }
}

void RandomAnser::start(){
    readData();
    menu();
}
