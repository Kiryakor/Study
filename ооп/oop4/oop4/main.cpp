#include <iostream>
#include <string>

using namespace std;

//MARK: Home
class Home{
protected:
    string name;
    float area;
    int cost;
    int peopleCount;
public:
    Home(string name,float area,int cost,int peopleCount);
    Home();
    virtual void print();
};

Home::Home(){
    this->name = "";
    this->area = 0;
    this->cost = 0;
    this->peopleCount = 0;
}

Home::Home(string name,float area,int cost,int peopleCount){
    this->name = name;
    this->area = area;
    this->cost = cost;
    this->peopleCount = peopleCount;
}

void Home::print(){
    cout << "Жилище" << endl;
    cout << "название " << name << endl;
    cout << "общая площадь " << area << endl;
    cout << "базовая стоимость проживания человека в сутки " << cost << endl;
    cout << "количество жильцов " << peopleCount << endl;
    cout << endl;
}

//MARK: House
class House: public Home{
private:
    string material;
    string privateOrRent;
public:
    void print() override;
    House(string material,string privateOrRent,int cost);
    House();
    int finalCost();
};

House::House(string material,string privateOrRent,int cost){
    this->cost = cost;
    this->material = material;
    this->privateOrRent = material;
}

House::House(){
    this->cost = 0;
    this->material = "";
    this->privateOrRent = "";
}

void House::print(){
    cout << "Дом" << endl;
    cout << "цена " << cost <<  endl;
    cout << "материал " << material << endl;
    cout << "частный или аренда - " << privateOrRent << endl;
    cout << endl;
}

int House::finalCost(){
    return 3500;
}

//MARK:Cottage
class Cottage: public Home{
private:
    int countFloor;
public:
    Cottage(float area,int countFloor);
    Cottage();
    int finalCost();
    void print() override;
};

Cottage::Cottage(){
    this->area = 0;
    this->countFloor = 0;
}

Cottage::Cottage(float area,int countFloor){
    this->area = area;
    this->countFloor = countFloor;
}

int Cottage::finalCost(){
    return peopleCount*750;
}

void Cottage::print(){
    cout << "Коттедж" << endl;
    cout << "площадь земельного участка " << area << endl;
    cout << "количество этажей " << countFloor << endl;
    cout << endl;
}

//MARK:Hostel
class Hostel: public Home{
private:
public:
    Hostel(int peopleCount);
    Hostel();
    int finalCost();
    void print() override;
};

Hostel::Hostel(int peopleCount){
    this->peopleCount = peopleCount;
}

Hostel::Hostel(){
    this->peopleCount = 0;
}

int Hostel::finalCost(){
    return peopleCount*250;
}

void Hostel::print(){
    cout << "Хостел" << endl;
    cout << "количество жителей " << peopleCount << endl;
    cout << endl;
}

//MARK: main
int main() {
    Home home("дом",76.4,2600,4);
    home.print();
    
    House house("дерево", "аренда", 4500);
    house.print();
    
    Cottage cottage(32.2, 2);
    cottage.print();
    
    Hostel hostel(13);
    hostel.print();
    return 0;
}
