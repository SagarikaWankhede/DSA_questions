#include <iostream>
#include <queue>
using namespace std;
void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0}; 
    for (char ch : s) {
        if (ch == ' ') continue; 
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << "\n";
}
int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}
