#include "Goods.h"
using namespace std;

// Функция для демонстрации копирования при передаче по значению
void View(Goods g) {
    cout << "--- Inside View function (by value) ---" << endl;
    g.Show();
}

// Функция для демонстрации копирования при возврате объекта
Goods CreateDiscounted(Goods& g) {
    Goods temp(g);
    temp.SetPrice(g.GetPrice() * 0.9f); // Скидка 10%
    cout << "--- Returning temporary object from function ---" << endl;
    return temp;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "--- 1. Static allocation ---" << endl;
    Goods item1("Bread", 10, 25.5);
    
    cout << "\n--- 2. Copy constructor (Initialization) ---" << endl;
    Goods item2 = item1; 

    cout << "\n--- 3. Copy constructor (Pass by value) ---" << endl;
    View(item1);

    cout << "\n--- 4. Copy constructor (Return value) ---" << endl;
    Goods item3 = CreateDiscounted(item1);

    cout << "\n--- 5. Pointer to object (Dynamic memory) ---" << endl;
    Goods* pItem = new Goods("Milk", 5, 60.0);
    pItem->Show();
    delete pItem; // Ручное удаление

    cout << "\n--- 6. Static array ---" << endl;
    Goods shelf[2] = {
        Goods("Apple", 50, 15.0),
        Goods("Orange", 30, 20.0)
    };

    cout << "\n--- 7. Dynamic array ---" << endl;
    Goods* stock = new Goods[2];
    stock[0].Set("Water", 100, 12.0);
    stock[1].Set("Juice", 40, 45.0);
    
    cout << "\n--- 8. Pointer to member function ---" << endl;
    void (Goods::*pf)() const = &Goods::Show;
    (stock[0].*pf)(); // Вызов через указатель на функцию
    (stock + 1)->Show();

    cout << "\n--- 9. Cleaning up dynamic array ---" << endl;
    delete[] stock;

    cout << "\n--- 10. End of program (Static objects destruction) ---" << endl;
    return 0;
}
#include "Goods.h"
using namespace std;

// Функция вызывает конструктор копирования (передача по значению)
void Display(Goods g) {
    g.Show();
}

int main() {
    // 1. Конструктор с параметрами (статическая память)
    Goods item1("Bread", 10, 25.5);

    // 2. Конструктор копирования (инициализация объекта другим объектом)
    Goods item2 = item1;

    // 3. Конструктор копирования (передача в функцию)
    Display(item1);
    // Здесь сработает деструктор для временного объекта g после выхода из Display

    // 4. Указатель на объект и динамическая память
    Goods* p = new Goods("Water", 100, 15.0); // Конструктор с параметрами
    
    // 5. Указатель на компонентную функцию
    void (Goods::*pf)() const = &Goods::Show;
    ((*p).*pf)(); // Вызов через указатель

    delete p; // Явный деструктор для динамического объекта

    // 6. Массив объектов (вызов конструктора по умолчанию 3 раза)
    Goods shelf[3];

    cout << "\n--- Завершение программы ---\n";
    return 0;
} // В конце сработают деструкторы для shelf[2..0], item2 и item1 (в обратном порядке)
