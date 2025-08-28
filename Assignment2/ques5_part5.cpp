#include <iostream>
using namespace std;
class Symmetric {
    int *A;
    int n;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2]; // Only store lower (or upper) part
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
        else A[j*(j-1)/2 + (i-1)] = x; // symmetric
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + (j-1)];
        else return A[j*(j-1)/2 + (i-1)];
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int n = 4;

    cout << "\nSymmetric Matrix:\n";
    Symmetric s(n);
    s.set(1,1,1); s.set(2,1,2); s.set(2,2,3);
    s.set(3,1,4); s.set(3,2,5); s.set(3,3,6);
    s.set(4,4,7);
    s.display();

    return 0;
}