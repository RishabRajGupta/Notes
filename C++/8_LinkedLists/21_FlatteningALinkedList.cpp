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
        Node* bottom;
    
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }

};

void InsertAtBottom(Node* &tail, int data){

    Node* temp = new Node(data);
    tail->bottom = temp;
    tail = temp;
}


void printBottom(Node* &head){
    
    if(!head){
        cout << endl;
        return;
    }

    cout << head->data << " ";
    
    printBottom(head->bottom); 
}


void printNext(Node* &head){
    
    if(!head){
        cout << endl;
        return;
    }

    cout << head->data << " ";
    
    printNext(head->next); 
}

Node* merge(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node* h1 = head1;
    Node* h2 = head2;
    Node* root = new Node(0);
    Node* curr = root;

    while(h1 && h2){
        if(h1->data <= h2->data){
            curr->bottom = h1;
            h1 = h1->bottom;
        }
        else{
            curr->bottom = h2;
            h2 = h2->bottom;
        }
        curr = curr->bottom;
    }

    curr->bottom = (h1) ? h1 : h2;
    
    return root->bottom;
}

Node* flatten(Node* root){

    if(!root || !root->next) return root;

    while(root->next){
        Node* h1 = root;
        Node* h2 = root->next;
        Node* h3 = root->next->next;
    

        h1->next = NULL;
        h2->next = NULL;

        root = merge(h1,h2);
        root->next = h3;
    }

    return root;
}

Node* flatten2(Node* root){
    if(!root || !root->next) return root;

    root->next = flatten2(root->next);
    root = merge(root, root->next);
    return root;
}

int main(){

    Node* root = new Node(5);
    Node* head = root;
    Node* tail = root;
    InsertAtBottom(tail, 7); InsertAtBottom(tail, 8);
    InsertAtBottom(tail, 30);                                   // 5-7-8-30

    Node* node2 = new Node(10);
    Node* tail2 = node2;    Node* head2 = node2;
    InsertAtBottom(tail2, 20); InsertAtBottom(tail2, 40);       // 10-20-40

    Node* node3 = new Node(19);
    Node* tail3 = node3;    Node* head3 = node3;
    InsertAtBottom(tail3, 22); InsertAtBottom(tail3, 50);       // 19-22-50

    Node* node4 = new Node(28);
    Node* tail4 = node4;    Node* head4 = node4;
    InsertAtBottom(tail4, 35); InsertAtBottom(tail4, 40);
    InsertAtBottom(tail4, 45);                                  // 28-35-40-45

    Node* node5 = new Node(30);
    Node* tail5 = node5;    Node* head5 = node5;
    InsertAtBottom(tail5, 34); InsertAtBottom(tail5, 40);       // 30-34-40

    root->next = node2; node2->next = node3;
    node3->next = node4; node4->next = node5;

    printBottom(root); printBottom(node2); printBottom(node3); printBottom(node4);
    printBottom(node5);         printNext(root);          cout << endl;
    Node* merged = flatten2(root);
    printBottom(merged);


}