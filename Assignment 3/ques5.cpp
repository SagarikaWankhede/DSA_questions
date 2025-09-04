#include <iostream>
#include <stack>
#include <string>
#include <cmath>  
using namespace std;
int evaluatePostfix(string postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top(); 
}
int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;
    return 0;
}
