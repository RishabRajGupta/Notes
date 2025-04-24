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

bool checkPalindrome(Node* head){

    if(!head || !head->next){
        return true;
    }

    //find mid
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //rotate
    Node* prev = NULL;
    Node* curr = slow; 
    while(curr){
        Node* fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    Node* head2 = prev;
    Node* head1 = head;

    //check
    while(head1 && head2){
        cout << head1->data << " " << head2->data << endl;
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    } 
    return true;
}

int main(){

    LinkedLists list(10);
    list.InsertAtTail(10);
    list.InsertAtTail(20);
    list.InsertAtTail(30);
    list.InsertAtTail(40);
    list.InsertAtTail(30);
    list.InsertAtTail(20);
    list.InsertAtTail(10);
    list.print();
    Node* head = list.getHead();
    cout << checkPalindrome(head) << endl;

}