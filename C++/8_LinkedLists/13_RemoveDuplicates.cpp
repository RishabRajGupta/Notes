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

//Method1
void removeDuplicates(Node* head){

    if(!head || !head->next){
        return;
    }

    vector<int> elements;
    Node* temp = head;
    elements.push_back(temp->data);
    temp = temp->next;
    while(temp){
        if(elements.back() != temp->data){
            elements.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head;
    for(int i = 0; i < elements.size(); i++){
        temp->data = elements[i];
        if(i == elements.size()-1){
            temp->next = NULL;
        }
        temp = temp->next;
    }
}

//Method2
void removeDuplicatesShort(Node* head){
    
    if(!head || !head->next){
        return;
    }

    Node* curr = head->next;
    Node* prev = head;
    while(curr){
        if(prev->data != curr->data){
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    prev->next = NULL;
}

int main(){

    LinkedLists list(10);
    list.InsertAtTail(10);
    list.InsertAtTail(20);
    list.InsertAtTail(20);
    list.InsertAtTail(40);
    list.InsertAtTail(40);
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.InsertAtTail(50);
    list.print();
    Node* head = list.getHead();
    removeDuplicatesShort(head);
    list.print();

}