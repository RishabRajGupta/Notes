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

Node* add(Node* head1, Node* head2){
    if(!head1 || !head2){
        Node* head = (!head1)?head2:head1;
        return head;
    }

    head1 = reverse(head1);
    head2 = reverse(head2);

    int carry = 0;
    Node* curr1 = head1; Node* curr2 = head2;
    Node* node3 = new Node(0);      //dummy node
    Node* head3 = node3;    Node* curr3 = node3;

    while(curr1 && curr2){
        
        int sum = curr1->data + curr2->data + carry;
        curr3->next = new Node(sum % 10);

        
        curr3 = curr3->next;
        curr1 = curr1->next; 
        curr2 = curr2->next;

        carry = sum/10;
    }

    //remaining elements
    while(curr1){
        int sum = curr1->data + carry;

        curr3->next = new Node(sum % 10);
        
        curr3 = curr3->next;
        curr1 = curr1->next;

        carry = sum/10;
    }
    while(curr2){
        int sum = curr2->data + carry;

        curr3->next = new Node(sum % 10);
        
        curr3 = curr3->next;
        curr2 = curr2->next;

        carry = sum/10;
    }

    if(carry != 0){
        curr3->next = new Node(carry);
        carry = 0;
    }
    
    //remove dummy node and reverse
    head3 = head3->next;
    head3 = reverse(head3);

    return head3;
}


int main(){

    Node* node1 = new Node(9);
    Node* head1 = node1;    Node* tail1 = node1;
    InsertAtTail(tail1, 8); InsertAtTail(tail1, 7);
    InsertAtTail(tail1, 6); InsertAtTail(tail1, 5);
    InsertAtTail(tail1, 4); // 9-8-7-6-5-4

    Node* node2 = new Node(6);
    Node* head2 = node2;    Node* tail2 = node2;
    InsertAtTail(tail2, 4); InsertAtTail(tail2, 3);
    InsertAtTail(tail2, 2); // 6-4-3-2

    Node* head3 = add(head1, head2);
    print(head3);

}