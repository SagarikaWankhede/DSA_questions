#include <iostream>
using namespace std;
class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2]; 
    }
    void set(int i, int j, int x) {
        if (i-j == 0) A[n-1+i-1] = x;         
        else if (i-j == 1) A[i-2] = x;        
        else if (i-j == -1) A[2*n-1 + i-1] = x; 
    }
    int get(int i, int j) {
        if (i-j == 0) return A[n-1+i-1];
        else if (i-j == 1) return A[i-2];
        else if (i-j == -1) return A[2*n-1 + i-1];
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
int main() {
    int n = 4;

    cout << "\nTri-diagonal Matrix:\n";
    TriDiagonal t(n);
    t.set(1,1,1); t.set(1,2,2);
    t.set(2,1,3); t.set(2,2,4); t.set(2,3,5);
    t.set(3,2,6); t.set(3,3,7); t.set(3,4,8);
    t.set(4,3,9); t.set(4,4,10);
    t.display();

    return 0;
}
