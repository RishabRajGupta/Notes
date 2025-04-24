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

class stacks{
    
    //properties
    public:
        int *arr;
        int size;
        int top;

    //constructor
    stacks(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    //functions
    bool push(int x){
        if(top >= size-1){
            cerr << "Stack Overflow" << endl;
            return 0;
        }
        arr[++top] = x;
        return true;
    }

    int pop(){
        if(top < 0){
            cerr << "Stack Underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    int peek(){
        if(top < 0){
            cerr << "Stack empty" << endl;
            return 0;
        }
        return arr[top];
    }

    int empty(){
        return (top < 0);
    }

};

int main() {

    //stack in STL
    stack<int> s;
    
    int count = 1;
    for(int i = 0; i < 5; i++){
        s.push(count++);
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    } cout << endl;

    //stack using class and array
    stacks st(5);

    for(int i = 0; i < 5; i++){
        st.push(count++);
    }

    while(!st.empty()){
        cout << st.peek() << " ";
        st.pop();
    } cout << endl;
        
}