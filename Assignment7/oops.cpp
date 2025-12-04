

#include <iostream>
using namespace std;
class Values {
    int a, b, c;
public:
    Values() {
        a = b = c = 0;
    }
    void operator()(int x, int y) {
        a = x;
        b = y;
    }
    void operator()(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }
    void show() {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};
int main() {
    Values v;
    v(10, 20);     
    v.show();
    v(1, 2, 3);    
    v.show();
    return 0;
}

