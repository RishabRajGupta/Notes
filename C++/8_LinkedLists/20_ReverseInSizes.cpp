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

class Node{
    public:
        int data;
        Node* next;
    
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void InsertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    
    if(!head){
        cout << endl;
        return;
    }

    cout << head->data << " ";
    
    print(head->next); 
}

Node* reverseInSize(Node* head, int size){
    if(!head || !head->next){
        return head;
    }

    Node* first = new Node(0);
    first->next = head;
    head = first;
    
    while(first->next){

        Node* second = first->next;
        Node* prev = first;
        Node* curr = first->next;
        Node* front;
        int x = size;
        
        while(x && curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        first->next = prev;
        second->next = curr;

        first = second;
    }
    
    first = head;
    head = head->next;
    delete first;

    return head;
}

int main(){

    Node* node = new Node(9);
    Node* head = node;    Node* tail = node;
    InsertAtTail(tail, 8); InsertAtTail(tail, 7);
    InsertAtTail(tail, 6); InsertAtTail(tail, 5);
    InsertAtTail(tail, 4); InsertAtTail(tail, 3);
    InsertAtTail(tail, 2); InsertAtTail(tail, 1);
    InsertAtTail(tail, 0);  print(head);

    head = reverseInSize(head, 4);

    print(head);

}