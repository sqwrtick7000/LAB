#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, m, a;    
    if (!(cin >> n >> m >> a)) {
        cout << "Ошибка: Введите числовые значения!" << endl;
        return 1;
    }
    if (n <= 0 || m <= 0 || a <= 0) {
        cout << "Ошибка: Размеры должны быть больше нуля!" << endl;
    } else {
        long long stones_n = ceil(n / a);
        long long stones_m = ceil(m / a);
        long long answer = stones_n * stones_m;
        cout << "Нужное количество плит: " << answer << endl;
    }
    return 0;
}