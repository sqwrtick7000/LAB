
#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, res = "";
    cin >> x;
    for (char c : x) {
        char lc = tolower(c);
        if (lc != 'a' && lc != 'o' && lc != 'y' && lc != 'e' && lc != 'u' && lc != 'i') {
            res += '.';
            res += lc;
        }
    }
    cout << res << endl;
    return 0;
}
