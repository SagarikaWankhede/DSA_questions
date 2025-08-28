#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int rows, cols, num;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> rows >> cols >> num;

    Element A[20], T[20]; 
    cout << "Enter row col value:\n";
    for (int i = 0; i < num; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    // Transpose
    int k = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < num; j++) {
            if (A[j].col == i) {
                T[k].row = A[j].col;
                T[k].col = A[j].row;
                T[k].val = A[j].val;
                k++;
            }
        }
    }

    cout << "\nTranspose in triplet form:\nRow Col Val\n";
    for (int i = 0; i < k; i++) {
        cout << T[i].row << "   " << T[i].col << "   " << T[i].val << endl;
    }
    return 0;
}