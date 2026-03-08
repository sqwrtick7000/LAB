#include "Goods.h"
using namespace std;

// Конструктор без параметров
Goods::Goods() {
    name = new char[8];
    strcpy(name, "NoName");
    amount = 0;
    price = 0.0f;
    cout << "[Constructor] Default called for object at " << this << " (" << name << ")" << endl;
}

// Конструктор с параметрами
Goods::Goods(const char* n, int a, float p) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    amount = a;
    price = p;
    cout << "[Constructor] Parametric called for object at " << this << " (" << name << ")" << endl;
}

// Конструктор копирования
Goods::Goods(const Goods& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    amount = other.amount;
    price = other.price;
    cout << "[Constructor] Copy called for object at " << this << " (copied from " << &other << ")" << endl;
}

// Деструктор
Goods::~Goods() {
    cout << "[Destructor] Called for object at " << this << " (" << (name ? name : "NULL") << ")" << endl;
    delete[] name;
}

// Геттеры и сеттеры
const char* Goods::GetName() const { return name; }
int Goods::GetAmount() const { return amount; }
float Goods::GetPrice() const { return price; }

void Goods::SetName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Goods::SetAmount(int a) { amount = a; }
void Goods::SetPrice(float p) { price = p; }

void Goods::Set(const char* n, int a, float p) {
    SetName(n);
    amount = a;
    price = p;
}

void Goods::Show() const {
    cout << "Goods: " << name << " | Amount: " << amount << " | Price: " << price << endl;
}