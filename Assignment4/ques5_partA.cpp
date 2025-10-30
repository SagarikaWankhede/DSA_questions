#include <iostream>
#include <queue>
using namespace std;
class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
        cout << x << " pushed\n";
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << " popped\n";
        q1.pop();
        swap(q1, q2);
    }
    void top() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Top element: " << q1.front() << "\n";
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
    }
    bool empty() {
        return q1.empty();
    }
};
