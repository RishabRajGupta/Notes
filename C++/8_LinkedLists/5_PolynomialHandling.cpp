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

struct Node{
    int coeff;
    int pow;
    Node* next;

    Node(int coeff, int pow){
        this->coeff = coeff;
        this->pow = pow;
        this->next = NULL;
    }
};

void InsertValue(Node* &head, int coeff, int pow){

    if(head == NULL || head->pow < pow){
        Node* temp = new Node(coeff, pow);
        head = temp;
        return;
    }
    Node* tracker = head;

    while(tracker->next != NULL && tracker->next->pow >= pow){
        tracker = tracker->next;
    }

    Node* temp = new Node(coeff, pow);
    tracker->next = temp;
    return;
}

void print(Node* head){
    
    if(head == NULL){
        return;
    }
    if(head->next != NULL){
        cout << head->coeff << "x^" << head->pow << " + ";
    }
    else if(head->pow == 0){
        cout << head->coeff << endl;
    }
    else if(head->next == NULL){
        cout << head->coeff << "x^" << head-> pow << endl;
    }
    
    print(head->next);
}

Node* addPoly(Node* head1, Node* head2){
    
    Node* temp = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->pow > head2-> pow){
            InsertValue(temp, head1->coeff, head1->pow);
            head1 = head1->next;
        }
        else if(head1->pow < head2-> pow){
            InsertValue(temp, head2->coeff, head2->pow);
            head2 = head2->next;
        }
        else if(head1->pow == head2-> pow){
            InsertValue(temp, head2->coeff+head1->coeff, head2->pow);
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return temp;
}

int main() {

    Node* poly1 = NULL;
    
    InsertValue(poly1, 3, 3);
    InsertValue(poly1, 5, 2);
    InsertValue(poly1, 6, 0);
    
    Node* poly2 = NULL;

    InsertValue(poly2, 2, 3);
    InsertValue(poly2, 7, 2);
    InsertValue(poly2, 4, 1);
    InsertValue(poly2, 5, 0);

    print(poly1);
    print(poly2);

    Node* poly3 = addPoly(poly1, poly2);
    print(poly3);
  
}