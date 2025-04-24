#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    Node* top;
    int length;
    int currSize;
    
    public :
        Stack(int size){
            this->top = NULL;
            this->length = size;
            this->currSize = 0;
        }
    
    bool push(int data){
        if(currSize >= length){
            cerr << "Stack Overflow" << endl;
            return false;
        }

        Node* temp = new Node(data);
        temp->next = top;
        top = temp; currSize++;
        return true;
    }

    bool pop(){
        if(currSize <= 0){
            cerr << "Stack Underflow" << endl;
            return false;
        }

        Node* temp = top;
        top = top->next;
        delete temp;    currSize--;
        return true;
    }

    int peek(){
        if(!top){
            cerr << "Stack Underflow" << endl;
            return 0;
        }
        return top->data;
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return (currSize <= 0);
    }

    void print(){
        Node* temp = top;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }   cout << endl;
    } 
};

int main(){

    Stack s(4);
    cout << s.peek() << endl;
    s.push(1);  s.push(2);
    s.push(3);  s.push(4);
    s.pop();    s.push(5);
    cout << s.peek() << " " << s.size() << " " << s.isEmpty() << endl;
    s.print();

}