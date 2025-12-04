#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;
    PriorityQueue() {
        size = 0;
    }
    void insert(int value) {
        arr[size] = value;
        int i = size;
        size++;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
    int extractMax() {
        if (size == 0)
            return -1;
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;
            if (largest == i)
                break;
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        }
        return maxVal;
    }
};
int main() {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(50);
    cout << pq.extractMax() << endl; 
    cout << pq.extractMax() << endl; 
    return 0;
}
