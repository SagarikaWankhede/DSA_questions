#include <iostream>
using namespace std;
class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2]; // Only store upper part
    }
    void set(int i, int j, int x) {
        if (i <= j) A[j*(j-1)/2 + (i-1)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[j*(j-1)/2 + (i-1)];
        return 0;
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
