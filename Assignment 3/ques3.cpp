#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;  
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }
    return s.empty();
}
int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Expression has balanced parentheses." << endl;
    else
        cout << "Expression does NOT have balanced parentheses." << endl;
    return 0;
}
