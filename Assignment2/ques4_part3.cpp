#include <iostream>
#include <cctype>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';  // null terminate

    cout << "String without vowels: " << str << endl;
    return 0;
}
