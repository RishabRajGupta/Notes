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

void InsertAtHead(Node* &head, int data){
    
    Node* temp = new Node(data);        //create new node -> store data
    temp->next = head;                  //store address of previous node
    head = temp;                        //shift head pointer to new node
}

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

void InsertInMiddle(Node* &head, Node* &tail, int pos, int data){

    if(pos == 1){
        InsertAtHead(head, data);
        return;
    }

    Node* track = head;
    for(int i = 1; i < pos-1; i++){
        track = track->next;
    }

    // not actually required
    // if(track->next == NULL){
    //     InsertAtTail(tail, data);
    //     return;
    // }

    Node* temp = new Node(data);
    temp->next = track->next;
    track->next = temp;
}

void deleteNode(Node* &head, int pos){
    
    Node* track = head;
    if(pos == 1){
        head = head->next;
        track->next = NULL;
        delete track;
        return;
    }

    for(int i = 1; i < pos-1; i++){
        track = track->next;
    }

    Node* curr = track->next;
    track->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtTail(tail, 20);
    print(head);
    InsertAtTail(tail, 30);
    print(head);
    InsertInMiddle(head, tail, 4, 25);
    print(head);
    deleteNode(head, 3);
    print(head);
    cout << head->data << " " << tail->data << endl;
     
}