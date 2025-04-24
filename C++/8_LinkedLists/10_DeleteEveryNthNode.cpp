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
        this->data = value;
        this->next = NULL;
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

Node* DeleteN(Node* head, int n){
    if(!head || n == 1){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;
    while(curr){
        if(count == n){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        }
        else{
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return head;
}

int main(){

    LinkedLists list(10);
    list.InsertAtTail(10);
    list.InsertAtTail(20);
    list.InsertAtTail(30);
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.InsertAtTail(60);
    list.InsertAtTail(70);
    list.print();
    Node* head = list.getHead();
    head = DeleteN(head,2);
    list.print();

}