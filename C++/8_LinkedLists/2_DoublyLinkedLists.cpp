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
        Node* prev;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    
    if(!head){
        cout << endl;
        return;
    }
    
    cout << head->data << " ";
    print(head->next);
}

void InsertAtHead(Node* &head, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void InsertInMiddle(Node* &head, Node* &tail, int pos, int data){

    if(pos == 1){
        InsertAtHead(head, data);
        return;
    }
    
    Node* tracker = head;
    for(int i = 1; i < pos-1; i++){
        tracker = tracker->next;
    }

    if(tracker->next == NULL){
        InsertAtTail(tail,data);
        return;
    }

    Node* temp = new Node(data);
    temp->prev = tracker;
    temp->next = tracker->next;
    tracker->next->prev = temp;
    tracker->next = temp;

}

void deleteNode(Node* &head, int pos){
    Node* tracker = head;
    for(int i = 1; i < pos-1; i++){
        tracker = tracker->next;
    }
    Node* temp = tracker->next;
    tracker->next = temp->next;
    temp->next->prev = tracker;
    temp = NULL;
    delete temp;
}

int main() {
   
   Node* node = new Node(10);
   Node* head = node;
   Node* tail = node;
   print(head);
   InsertAtHead(head, 20);
   InsertAtHead(head, 30);
   print(head);
   InsertAtTail(tail,5);
   InsertAtTail(tail,0);
   print(head);
   InsertInMiddle(head,tail,3,15);
   print(head);
   deleteNode(head,3);
   print(head);


}