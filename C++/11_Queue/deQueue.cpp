#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

class DeQueue {
public:
    int *arr;
    int front;
    int back;
    int size;
    int currSize;

    DeQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = size - 1;
        back = 0;
        currSize = 0;
        fill(arr, arr + size, -1);
    }

    bool push_front(int element) {
        if (currSize == size) {
            cout << "Queue Full!" << endl;
            return false;
        }
        arr[front] = element;
        front = (front == 0) ? size - 1 : front - 1;
        currSize++;
        return true;
    }

    bool push_back(int element) {
        if (currSize == size) {
            cout << "Queue Full!" << endl;
            return false;
        }
        arr[back] = element;
        back = (back + 1) % size;
        currSize++;
        return true;
    }

    int pop_front() {
        if (currSize == 0) {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        front = (front + 1) % size;
        int x = arr[front];
        arr[front] = -1;
        currSize--;
        return x;
    }

    int pop_back() {
        if (currSize == 0) {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        back = (back == 0) ? size - 1 : back - 1;
        int x = arr[back];
        arr[back] = -1;
        currSize--;
        return x;
    }

    int dqsize() {
        return currSize;
    }

    bool isEmpty() {
        return currSize == 0;
    }
};

int main() {
    DeQueue dq(4);
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(3);
    dq.push_back(4);
    dq.push_back(3);
    cout << "Popping elements from the front: ";
    while (!dq.isEmpty()) {
        cout << dq.pop_front() << " ";
    }

    cout << endl;
    dq.push_back(4);
    dq.push_back(3);
    dq.push_back(6);
    dq.push_front(5);
    dq.push_front(6);
    cout << "Popping elements from the back: ";
    while (!dq.isEmpty()) {
        cout << dq.pop_back() << " ";
    }

    return 0;
}
