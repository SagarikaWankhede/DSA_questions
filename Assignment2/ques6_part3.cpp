#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int r1, c1, n1, r2, c2, n2;
    cout << "Enter rows, cols of A: ";
    cin >> r1 >> c1;
    cout << "Enter non-zero elements in A: ";
    cin >> n1;

    Element A[20];
    cout << "Enter row col value for A:\n";
    for (int i = 0; i < n1; i++) cin >> A[i].row >> A[i].col >> A[i].val;

    cout << "Enter rows, cols of B: ";
    cin >> r2 >> c2;
    cout << "Enter non-zero elements in B: ";
    cin >> n2;

    Element B[20];
    cout << "Enter row col value for B:\n";
    for (int i = 0; i < n2; i++) cin >> B[i].row >> B[i].col >> B[i].val;

    if (c1 != r2) {
        cout << "Multiplication not possible!\n";
        return 0;
    }

    Element C[40];
    int k = 0;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int x = 0; x < n1; x++) {
                if (A[x].row == i) {
                    for (int y = 0; y < n2; y++) {
                        if (B[y].col == j && A[x].col == B[y].row) {
                            sum += A[x].val * B[y].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }

    cout << "\nMultiplication Result (triplet form):\nRow Col Val\n";
    for (int i = 0; i < k; i++)
        cout << C[i].row << "   " << C[i].col << "   " << C[i].val << endl;

    return 0;
}