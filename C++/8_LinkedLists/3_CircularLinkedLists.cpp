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

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &tail){

    if(tail == NULL){
        cout << "Empty!" << endl;
        return;
    }
    
    Node* temp = tail;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);

    cout << endl;
}

//insert (data) after (element) in Linked list
void insert(Node* &tail, int element, int data){
    
    //empty
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;      //circular property
        return;
    }

    //non-empty
    Node* temp = new Node(data);
    
    Node* tracker = tail;
    while(tracker->data != element){
        tracker = tracker->next;
    }

    temp->next = tracker->next;
    tracker->next = temp;
}

void deleteNode(Node* &tail, int element){
    
    if(tail == NULL){
        cout << "Empty!" << endl;
        return;
    }

    Node* tracker = tail;
    while(tracker->next->data != element){
        tracker = tracker->next;
    }
    
    if(tail->data == element){
        tail = tail->next;    
    }

    Node* temp = tracker->next;
    tracker->next = temp->next;
    
    temp = NULL;
    delete temp;

}


int main() {

    Node* tail = NULL;
    insert(tail, 0, 10);
    print(tail);
    insert(tail, 10, 20);
    insert(tail, 20, 30);
    insert(tail, 30, 40);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
}