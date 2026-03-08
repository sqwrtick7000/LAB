#ifndef GOODSH
#define GOODSH

#include <iostream>
#include <cstring>

class Goods {
    char* name;    // имя товара
    int amount;    // количество
    float price;   // стоимость

public:
    // 2. Конструкторы
    Goods();                                   // без параметров
    Goods(const char* n, int a, float p);      // с параметрами
    Goods(const Goods& other);                 // копирования

    // 3. Деструктор
    ~Goods();

    // 4. Компоненты-функции (геттеры и сеттеры)
    const char* GetName() const;
    int GetAmount() const;
    float GetPrice() const;

    void SetName(const char* n);
    void SetAmount(int a);
    void SetPrice(float p);
    
    void Set(const char* n, int a, float p);
    void Show() const;
};

#endif