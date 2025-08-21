#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (isupper(ch)) {
        ch = tolower(ch);
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Character is not uppercase!" << endl;
    }

    return 0;
}