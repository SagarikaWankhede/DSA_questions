#include <iostream>
#include <queue>
using namespace std;
class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed\n";
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }
    void top() {
        if (q.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        cout << "Top element: " << q.front() << "\n";
    }
    bool empty() {
        return q.empty();
    }
};
int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.top();   
    s.pop();   
    s.top();   
    s.pop();  
    s.top();   
    return 0;
}
