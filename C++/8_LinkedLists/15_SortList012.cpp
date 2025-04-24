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

void Sort(Node* head){
    
    int* arr = new int[3];
    Node* temp = head;

    while(temp){
        arr[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0;i < 3; i++){
        for(int j = 0; j < arr[i]; j++){
            temp->data = i;
            temp = temp->next;
        }
    }
    
}
bool detectLoop(Node* tail){
    if(!tail || !tail->next){
        return false;
    }
    vector<Node*> visited;
    Node* temp = tail;
    while(temp != NULL){
        for(int i = 0; i < visited.size(); i++){
            if(temp == visited[i]){
                cout << "Loop detected!" << endl;
                return true;
                break;
            }
        }
        visited.push_back(temp);
        temp = temp->next;
    }
    cout << "No Loop detected!" << endl;
    return false;
}

int main(){

    LinkedLists list(10);
    list.InsertAtTail(1);  list.InsertAtTail(2);
    list.InsertAtTail(0);  list.InsertAtTail(0);
    list.InsertAtTail(2);  list.InsertAtTail(1);
    list.InsertAtTail(1); Node* head = list.getHead();
    list.print();
    Sort(head);
    list.print();

}