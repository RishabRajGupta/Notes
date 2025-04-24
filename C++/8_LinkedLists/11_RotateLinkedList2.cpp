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

void Rotate(Node* &head, int rotations){

    if(!head || !head->next || rotations == 0){
        return;
    }
    
    vector<int> elements;
    Node* temp = head;
    while(temp){
        elements.push_back(temp->data);
        temp = temp->next;
    }
    
    rotations = rotations % elements.size();
    if(rotations == 0){
        return;
    }
    int i = 0, j = elements.size()-rotations, k = j;
    temp = head;
    while(temp){
        if(j < elements.size()){
            temp->data = elements[j++];
        }
        else if(j == elements.size() && i < k){
            temp->data = elements[i++];
        }
        temp = temp->next;
    }
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
    Rotate(head, 4);
    list.setHead(head);
    list.print();

}