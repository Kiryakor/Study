////
////  main.cpp
////  tinder
////
////  Created by Кирилл on 22.02.2020.
////  Copyright © 2020 Кирилл. All rights reserved.
////
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
////MARK: Cтруктуры
//struct Photo{
//    string href;
//    string description;
//};
//
//struct User{
//    string login;
//    string password;
//    vector<string> followers;
//    vector<Photo> photoVector;
//};
//
////MARK: Class
//class Instagramm{
//private:
//    const string path = "/Users/kirill/Desktop/tinder/tinder/file.txt";
//    vector<User> dataAllUser;
//    User activeUser;
//    //обработка строки из файла
//    void readDataSupport(string data);
//    // регистрация
//    void registration();
//    // вход
//    void entrance();
//    //menu
//    void menu();
//    //add image
//    void addImage();
//    //finc people
//    void findPeople();
//    //просмотр фото
//    void lookPhotoActiveUser();
//    //просмотр подписчиков
//    void lookFollowers();
//    //редактирование данных своих
//    void editData();
//    //редактирование описания у фотографий
//    void editDescriptionPhoto();
//    //удаление фотографий
//    void removePhoto();
//    //save
//    void saveAndClose();
//    //старт
//    void start();
//    //info
//    void info();
//public:
//    //считывание данных
//    void readData();
//};
//
//int main() {
//    Instagramm insta;
//    insta.readData();
//    return 0;
//}
//
////MARK: Считывание данных из файла
//void Instagramm::readDataSupport(string data){
//    User user;
//    string line;
//    int count = 0;
//    vector<string> followers;
//    vector<Photo> photoVector;
//    Photo photo;
//    for (int i=0;i<data.length();i++){
//        if (data[i]!='#' && count==0){
//            line+=data[i];
//        }else if (data[i]=='#' && count==0){
//            user.login = line;
//            line = "";
//            count++;
//        }else if (data[i]!='#' && count==1){
//            line+=data[i];
//        }else if (data[i]=='#' && count==1){
//            user.password = line;
//            count++;
//            line = "";
//        }else if (data[i]!='*' && count==2){
//            if (data[i]!='!'){
//                line+=data[i];
//            }else{
//                followers.push_back(line);
//                line = "";
//            }
//        }else if (data[i]=='*' && count==2){
//            count++;
//            user.followers = followers;
//            line = "";
//        }else{
//            if (data[i]!=' ' && data[i]!='|'){
//                line+=data[i];
//            }else if (data[i]==' '){
//                photo.description = line;
//                line = "";
//            }else if (data[i]=='|'){
//                photo.href = line;
//                line = "";
//                photoVector.push_back(photo);
//            }
//        }
//    }
//    user.photoVector = photoVector;
//    dataAllUser.push_back(user);
//}
//
//void Instagramm::readData(){
//    ifstream file(path);
//    if (!file) {
//        cout << "файл не найден" << endl;
//    } else {
//        string data;
//        while (getline(file, data)) {
//            readDataSupport(data);
//        }
//        file.close();
//    }
//    start();
//}
//
////MARK: Вход в приложение
//void Instagramm::start(){
//    int choose;
//    cout << "Выберите пункт меню " << endl;
//    cout << "1 - авторизация " << endl;
//    cout << "2 - регистрация " << endl;
//    cin >> choose;
//    switch (choose) {
//        case 1:
//            entrance();
//            break;
//        case 2:
//            registration();
//            break;
//        default:
//            cout << "error" << endl;
//            break;
//    }
//}
//
//void Instagramm::registration(){
//    string login, password, password2;
//    cout << "Введите логин " << endl;
//    cin >> login;
//    cout << "Введите пароль " << endl;
//    cin >> password;
//    cout << "Введите пароль еще раз " << endl;
//    cin >> password2;
//    if (password == password2){
//        cout << "Вы успешно зарегистрировались " << endl;
//        User user;
//        user.login = login;
//        user.password = password;
//        dataAllUser.push_back(user);
//        activeUser = user;
//        menu();
//    }else{
//        cout << "Пароли не совпадают " << endl;
//    }
//}
//
//void Instagramm::entrance(){
//    string login, password;
//    cout << "Введите логин " << endl;
//    cin >> login;
//    cout << "Введите пароль " << endl;
//    cin >> password;
//
//    for(int i=0;i<dataAllUser.size();i++){
//        if (dataAllUser[i].login == login){
//            if(dataAllUser[i].password == password){
//                activeUser = dataAllUser[i];
//                cout << "Вы успешно авторизировались " << endl;
//                menu();
//            }else {
//                cout << "Пароль введен неверно " << endl;
//            }
//            break;
//        }
//    }
//}

//MARK: меню
void Instagramm::menu(){
    int choose = -1;
    system("cls");
    while (choose!=8) {
        cout << "Меню" << endl;
        cout << "1 - просмотр своих фотографий" << endl;
        cout << "2 - добавление фотографий " << endl;
        cout << "3 - удаление своих фотографий " << endl;
        cout << "4 - редактирование описания у фотографий " << endl;
        cout << "5 - редактирование своих данный login/password " << endl;
        cout << "6 - просмотр подписок " << endl;
        cout << "7 - поиск пользователей " << endl;
        cout << "8 - выход и сохранение данных " << endl;
        cout << "9 - информация о программе " << endl;
        cin >> choose;
        switch (choose) {
            case 1:
                lookPhotoActiveUser();
                break;
            case 2:
                addImage();
                break;
            case 3:
                removePhoto();
                break;
            case 4:
                editDescriptionPhoto();
                break;
            case 5:
                editData();
                break;
            case 6:
                lookFollowers();
                break;
            case 7:
                findPeople();
                break;
            case 8:
                saveAndClose();
                break;
            case 9:
                info();
                break;
            default:
                break;
        }
    }
}

void Instagramm::addImage(){
    Photo photo;
    cout << "Введите ссылку на фотографию " << endl;
    cin >> photo.href;
    cout << "Введите описание " << endl;
    cin >> photo.description;
    activeUser.photoVector.push_back(photo);
    cout << "фото успешно добавлено " << endl;
}

void Instagramm::findPeople(){
    string login;
    bool find = false;
    cout << "Введите логин пользователя " << endl;
    cin >> login;
    for (int i=0;i<dataAllUser.size();i++){
        if(dataAllUser[i].login == login){
            find = true;
            cout << "Пользователь найден " << endl;
            cout << "1 - подписаться" << endl;
            cout << "2 - просмотреть фотографии " << endl;
            int choose;
            cin >> choose;
            switch (choose) {
                case 1:
                    activeUser.followers.push_back(dataAllUser[i].login);
                    cout << "Вы успешно подписались" << endl;
                    break;
                case 2:
                    for (int j=0;i<dataAllUser[j].photoVector.size();j++){
                        cout << dataAllUser[i].photoVector[j].href << "     " << dataAllUser[i].photoVector[j].description << endl;
                    }
                    if (dataAllUser[i].photoVector.size() == 0){
                        cout << "у пользователя нету фото" << endl;
                    }
                    break;
                default:
                    break;
            }
            break;
        }
    }
    if (!find){
        cout << "Пользователь не найден " << endl;
    }
}

void Instagramm::lookPhotoActiveUser(){
    for (int i=0;i<activeUser.photoVector.size();i++){
        cout << activeUser.photoVector[i].description << "->" << activeUser.photoVector[i].href << endl;
    }
    if (activeUser.photoVector.size() == 0){
        cout << "у вас нету фото" << endl;
    }
}

void Instagramm::lookFollowers(){
    for (int i=0;i<activeUser.followers.size();i++){
        cout << activeUser.followers[i] << endl;
    }
    if (activeUser.followers.size() == 0){
        cout << "у вас нету подписчиков" << endl;
    }
}

void Instagramm::editData(){
    cout << "Что вы хотите изменить ?" << endl;
    cout << "1 - логин" << endl;
    cout << "2 - пароль" << endl;
    int choose;
    cin >> choose;
    switch (choose) {
        case 1:{
            string login;
            int index = 0;
            cout << "Введите новый логин" << endl;
            cin >> login;
            for (int i=0;i<dataAllUser.size();i++){
                if (dataAllUser[i].login == activeUser.login){
                    index = i;
                    break;
                }
            }
            activeUser.login = login;
            dataAllUser[index] = activeUser;
            cout << "логин успешно изменен" << endl;
            break;
        }
        case 2:{
            string password,password2;
            cout << "Введите новый пароль " << endl;
            cin >> password;
            cout << "Повторите новый пароль" << endl;
            cin >> password2;
            if (password == password2){
                activeUser.password = password;
                cout << "Пароль успешно изменен" << endl;
            }else{
                cout << "Пароли разные " << endl;
            }
            break;
        }
        default:
            cout << "error" << endl;
            break;
    }
}

void Instagramm::editDescriptionPhoto(){
    cout << "Выберите номер фотографии, описание которой хотите изменить" << endl;
    for (int i=0;i<activeUser.photoVector.size();i++){
        cout << i+1 << ":" << activeUser.photoVector[i].description << " " << activeUser.photoVector[i].href << endl;
    }
    int index;
    cin >> index;
    cout << "Вы выбрали изображение :" << endl;
    cout << activeUser.photoVector[index-1].description << " " << activeUser.photoVector[index-1].href << endl;
    string description;
    cout << "Введите новое описание" << endl;
    cin >> description;
    activeUser.photoVector[index-1].description = description;
    cout << "Описание успешно изменёно" << endl;
}

void Instagramm::removePhoto(){
    cout << "Выберите номер фотографии, которую хотите удалить " << endl;
    for (int i=0;i<activeUser.photoVector.size();i++){
        cout << i+1 << ":" << activeUser.photoVector[i].description << ":" << activeUser.photoVector[i].href << endl;
    }
    int index;
    cin >> index;
    cout << "Вы выбрали изображение :" << endl;
    cout << activeUser.photoVector[index-1].href << " " << activeUser.photoVector[index-1].description << endl;
    activeUser.photoVector.erase(activeUser.photoVector.begin()+index-1);
    cout << "Изображение успешно удалено"<< endl;
}

void Instagramm::saveAndClose(){
    ofstream file(path);
    if (file.is_open()){
        for (int i=0;i<dataAllUser.size();i++){
            if (dataAllUser[i].login == activeUser.login){
                dataAllUser[i] = activeUser;
                break;
            }
        }
        for (int i=0;i<dataAllUser.size();i++){
            file << dataAllUser[i].login << "#" << dataAllUser[i].password << "#";
            for (int j=0;j<dataAllUser[i].followers.size();j++){
                file << dataAllUser[i].followers[j] << "!";
            }
            file << "*";
            for (int k=0;k<dataAllUser[i].photoVector.size();k++){
                file << dataAllUser[i].photoVector[k].description << " " << dataAllUser[i].photoVector[k].href << "|";
            }
            file << endl;
        }
    }else{
        cout << "файл не найден " << endl;
    }
}

void Instagramm::info(){
    cout << "Приложение для обмена фотографиями" << endl;
    cout << "Разработчик - Кирилл Корнющенков" << endl;
    cout << "Год выпуска - 2020" << endl;
}
