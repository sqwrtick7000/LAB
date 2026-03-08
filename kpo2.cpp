#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <chrono>
using namespace std;

long long binToDec(string bin) {
    long long res = 0;
    for (int i = 2; i < bin.length(); i++) {
        res = res * 2 + (bin[i] - '0');
    }
    return res;
}

void bubbleSortBinary(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (binToDec(arr[j]) > binToDec(arr[j + 1])) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void testBubbleSort() {
    // Тест 1: Обычный случай
    string arr1[] = {"0b11", "0b1", "0b10"};
    bubbleSortBinary(arr1, 3);
    assert(arr1[0] == "0b1" && arr1[1] == "0b10" && arr1[2] == "0b11");
    // Тест 2: Уже отсортированный
    string arr2[] = {"0b1", "0b10", "0b100"};
    bubbleSortBinary(arr2, 3);
    assert(arr2[0] == "0b1" && arr2[1] == "0b10" && arr2[2] == "0b100");
    // Тест 3: Обратный порядок
    string arr3[] = {"0b111", "0b11", "0b1"};
    bubbleSortBinary(arr3, 3);
    assert(arr3[0] == "0b1" && arr3[1] == "0b11" && arr3[2] == "0b111");
    // Тест 4: Одинаковые числа
    string arr4[] = {"0b10", "0b10", "0b1"};
    bubbleSortBinary(arr4, 3);
    assert(arr4[0] == "0b1" && arr4[1] == "0b10" && arr4[2] == "0b10");
    // Тест 5: Одно число
    string arr5[] = {"0b101"};
    bubbleSortBinary(arr5, 1);
    assert(arr5[0] == "0b101");
}


long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

long long fibIterative(int n) {
    if (n <= 1) return n;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

void testFibonacci() {
    // Тест 1: Базовый случай 0
    assert(fibIterative(0) == 0 && fibRecursive(0) == 0);
    // Тест 2: Базовый случай 1
    assert(fibIterative(1) == 1 && fibRecursive(1) == 1);
    // Тест 3: n = 5
    assert(fibIterative(5) == 5 && fibRecursive(5) == 5);
    // Тест 4: n = 10
    assert(fibIterative(10) == 55 && fibRecursive(10) == 55);
    // Тест 5: n = 20
    assert(fibIterative(20) == 6765 && fibRecursive(20) == 6765);
}

void compareTime(int n) {
    using namespace chrono;
    // Замер рекурсии
    auto startRec = high_resolution_clock::now();
    long long resRec = fibRecursive(n);
    auto endRec = high_resolution_clock::now();
    duration<double, milli> diffRec = endRec - startRec;
    // Замер итерации
    auto startIter = high_resolution_clock::now();
    long long resIter = fibIterative(n);
    auto endIter = high_resolution_clock::now();
    duration<double, milli> diffIter = endIter - startIter;
    cout << "\n--- Сравнение времени (n = " << n << ") ---\n";
   cout << "Рекурсия: " << resRec << " | Время: " << diffRec.count() << " мс\n";
    cout << "Итерация: " << resIter << " | Время: " << diffIter.count() << " мс\n";
    cout << "--------------------------------------\n";
}

int main() {
    testBubbleSort();
    testFibonacci();
    string myBinArr[] = {"0b1100100", "0b100101", "0b100"};
    int size = 3;
    cout << "\nМассив до сортировки: ";
    for(int i=0; i<size; i++) cout << myBinArr[i] << " ";
    bubbleSortBinary(myBinArr, size);
    cout << "\nМассив после сортировки: ";
    for(int i=0; i<size; i++) cout << myBinArr[i] << " ";
    cout << endl;
    compareTime(40);
    return 0;
}
