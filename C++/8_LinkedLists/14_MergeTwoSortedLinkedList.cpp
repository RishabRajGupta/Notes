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
    int data;
    Node* next;
    Node(int value){
        this->next = NULL;
        this->data = value;
    }
};

//No Use
class LinkedLists{
    private:
        Node* head;
        int size;
        int currSize;
        Node* tail;
    
    public:    
        LinkedLists(int givenSize){
        this->head = NULL;
        this->tail = NULL;
        this->size = givenSize;
        this->currSize = 0;
        }

        bool InsertAtTail(int value){
            
            if(currSize >= size){
                cerr << "No Space!" << endl;
                return false;
            }
            
            if(!tail){
                Node* temp = new Node(value);
                head = temp;
                tail = temp;
                currSize++;
                return true;
                
            }
            
            Node* temp = new Node(value);
            tail->next = temp;
            tail = temp;
            currSize++;
            return true;
        }

        bool print(){
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }   cout << endl;
            return true;
        }

        Node* getHead(){
            return head;
        }
        Node* getTail(){
            return tail;
        }
        void setHead(Node* newHead){
            this->head = newHead;
        }
        void setTail(Node* newTail){
            this->tail = newTail;
        }
};

Node* Merge(Node* h1, Node* h2){
    if (!h1) return h2;
    if (!h2) return h1;

    Node* result = NULL;

    if(h1->data <= h2->data){
        result = h1;
        h1 = h1->next;
    }
    else{
        result = h2;
        h2 = h2->next;
    }
    Node* temp = result;

    while(h1 && h2){
        if(h1->data <= h2->data){
            temp->next = h1;
            h1 = h1->next;
        }
        else{
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }
    
    temp->next = (h1) ? h1 : h2;
    return result;
}

int main(){

    LinkedLists list(10);
    list.InsertAtTail(10);  list.InsertAtTail(20);
    list.InsertAtTail(40);  list.InsertAtTail(80);
    list.InsertAtTail(90);  list.InsertAtTail(120);
    list.InsertAtTail(150); Node* head1 = list.getHead();
    list.print();
    
    LinkedLists list2(10);
    list2.InsertAtTail(15);  list2.InsertAtTail(30);
    list2.InsertAtTail(50);  list2.InsertAtTail(60);
    list2.InsertAtTail(70);  list2.InsertAtTail(100);
    list2.InsertAtTail(140);  Node* head2 = list2.getHead();
    list2.print();
    
    Node* head3 = Merge(head1, head2);
    Node* temp = head3;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;

}