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
                return true;
                currSize++;
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
};

Node* MiddleElement(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    
    Node* mid = MiddleElement(list.getHead());
    cout << "Middle Element : " << mid->data << endl;


}