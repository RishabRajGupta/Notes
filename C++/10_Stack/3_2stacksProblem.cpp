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

class twoStacks{
    public:
        int size;
        int top1;
        int top2;
        int *arr;

    twoStacks(int size){
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    bool push1(int x){
        if(top2 - top1 > 1){
            arr[++top1] = x;
            return true;
        }
        cout << "Stack Overflow 1" << endl;
        return false;
        
    }
    bool push2(int x){
        if(top2 - top1 > 1){
            arr[--top2] = x;
            return true;    
        }
        cout << "Stack Overflow 2" << endl;
        return false;
    }

    int pop1(){
        if(top1 >= 0){
            return arr[top1--];
        }
        cout << "Stack Underflow 1" << endl;
        return -1;
    }

    int pop2(){
        if(top2 < size){
            return arr[top2++];
        }
        cout << "Stack Underflow 2" << endl;
        return -1;
    }

    ~twoStacks(){
        delete [] arr;
    }

};

int main() {
    
    twoStacks ts(6);

    ts.push1(1);ts.push1(1);ts.push1(1);ts.push1(1);
    ts.push2(2);ts.push2(2);

    cout << ts.pop1() << " ";
    cout << ts.pop1() << " ";
    cout << ts.pop1() << " ";
    cout << ts.pop1() << endl;
    
    cout << ts.pop2() << " ";
    cout << ts.pop2() << endl;
    
}