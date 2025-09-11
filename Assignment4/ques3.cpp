#include <iostream>
#include <queue>
using namespace std;
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!\n";
        return;
    }
    int half = n / 2;
    queue<int> firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}
void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}
int main() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements (even): ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    cout << "Original Queue: ";
    display(q);
    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    display(q);
    return 0;
}
