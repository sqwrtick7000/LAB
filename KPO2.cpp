#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, res = "";
    if (!(cin >> x)) {
        cout << "Ошибка чтения ввода!" << endl;
        return 1;
    }
    if (x.empty()) {
        cout << "Строка пуста!" << endl;
        return 0;
    }
    for (char c : x) {
        char lc = tolower(c);
        if (lc != 'a' && lc != 'o' && lc != 'y' && lc != 'e' && lc != 'u' && lc != 'i') {
            res += '.';
            res += lc;
        }
    }
    if (res == "") {
        cout << "Результат пуст (все буквы были гласными)" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
