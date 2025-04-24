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

//Iterative Solution
Node* reverse(Node* head){
    if(!head || head->next == NULL){
        return head;
    }
     
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;
    while(curr){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

//Recursive Solution 1
void rev(Node* &head, Node* curr, Node* prev){
    //base case
    if(!curr){
        head = prev;
        return;
    }
    
    rev(head, curr->next, curr);
    curr->next = prev;

}
void reverseRecursion(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    rev(head, curr, prev);
}

//Recursive Solution 2
Node* reverseRecursion2(Node* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* tempHead = reverseRecursion2(head->next);
    head->next->next = head;
    head->next = NULL;

    return tempHead;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 50);
    print(head);
    head = reverse(head);
    cout << "Iterative Solution : "; print(head);
    reverseRecursion(head);
    cout << "Recursive Solution1 : "; print(head);
    head = reverseRecursion2(head);
    cout << "Recursive Solution2 : "; print(head);
}