#include <iostream>
#include <cassert>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void testIsPrime() {
    assert(isPrime(2) == true);   // 2 - наименьшее простое число
    assert(isPrime(4) == false);  // 4 - составное
    assert(isPrime(1) == false);  // 1 - не простое
    assert(isPrime(13) == true);  // 13 - простое
    assert(isPrime(25) == false); // 25 - квадрат простого (5*5)
}

void find100Primes() {
    int primes[100];
    int count = 0;
    int number = 2;
    while (count < 100) {
        if (isPrime(number)) {
            primes[count] = number;
            count++;
        }
        number++;
    }
    for (int i = 0; i < 100; i++){
     cout << primes[i] << " ";
    }
    cout << endl;
}

int compareSets(const double set1[8], const double set2[8]) {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < 8; ++i) {
        sum1 += set1[i];
        sum2 += set2[i];
    }
    if (sum1 < sum2) return 1;
    if (sum2 < sum1) return 2;
    return 0;
}

void testCompareSets() {
    double a[8] = {1, 1, 1, 1, 1, 1, 1, 1}; // сумма 8
    double b[8] = {2, 2, 2, 2, 2, 2, 2, 2}; // сумма 16
    double c[8] = {1, 1, 1, 1, 1, 1, 1, 1}; // сумма 8
    // Тест 1: Первый набор дешевле
    assert(compareSets(a, b) == 1);
    // Тест 2: Второй набор дешевле
    assert(compareSets(b, a) == 2);
    // Тест 3: Равная стоимость
    assert(compareSets(a, c) == 0);
    // Тест 4: Разные цены, но одна сумма
    double d1[8] = {10, 0, 0, 0, 0, 0, 0, 0};
    double d2[8] = {1, 1, 1, 1, 1, 1, 1, 3};
    assert(compareSets(d1, d2) == 0);
    // Тест 5: Дробные значения
    double e1[8] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5}; // 4.0
    double e2[8] = {1.0, 1.0, 1.0, 1.0, 0, 0, 0, 0};         // 4.0
    assert(compareSets(e1, e2) == 0);
}
int main() {
    testIsPrime();
    testCompareSets();
    cout << "\n--- Результаты работы ---\n" << endl;
    find100Primes();
    double setA[8];
    double setB[8];
    cout << "Введите эл. 1-го набора" << endl;
    for (int i = 0; i < 8; i++){
        cin>> setA[i];
    }
    cout << "Введите эл. 2-го набора" << endl;
    for (int i = 0; i < 8; i++){
        cin>> setB[i];
    }
    int result = compareSets(setA, setB);
    if (result == 1) {
       cout << "Набор 1 дешевле набора 2" << endl;
    } else if (result == 2) {
        cout << "Набор 2 дешевле набора 1" << endl;
    } else {
        cout << "Наборы стоят одинаково" << endl;
    }
    return 0;
}
