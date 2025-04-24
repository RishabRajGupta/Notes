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

//circular queue
class Queue{
    public:
        int *arr;
        int front;
        int back;
        int size;
        int currsize;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0; back = 0;
        currsize = 0;

        fill(arr, arr+size, -1);
    }

    bool enqueue(int element){
        if(currsize == size){
            cout << "Queue full!" << endl;
            return false;
        }

        arr[back] = element;
        back = (back+1) % size;
        currsize++; 
        
        return true;
    }
    bool dequeue(){
        if(currsize == 0){
            cout << "Queue empty!" << endl;
            return false;
        }

        arr[front] = -1;
        front = (front+1) % size;
        currsize--; 
        
        return true;
    }
    int frontelement(){
        if(currsize == 0){
            cout << "Queue empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isempty(){
        return currsize == 0;
    }
    int sizeq(){
        return currsize;
    }
};



int main() {

    queue<int> q;
    
    q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);
    cout << "Size : " << q.size() << endl;
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    } cout << endl;

    //implementing queue using array
    Queue cq(4);
    cq.enqueue(10); cq.enqueue(10); cq.enqueue(10); cq.enqueue(10);

    for(int i = 0; i < 2; i++){
        cq.dequeue();
    }
    cq.enqueue(20); cq.enqueue(30); cq.enqueue(40);
    while(!cq.isempty()){
        cout << cq.frontelement() << " ";
        cq.dequeue();
    } cout << endl;

    

    
    
        
}