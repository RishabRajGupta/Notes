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

class CircularLinkedLists{
    
    private :
        int currSize;
        int size;
        Node* tail;
    
    public :
        CircularLinkedLists(int size){
            this->size = size;
            this->currSize = 0;
            this->tail = NULL;
        }

        bool print(){
            if(!tail){
                cout << "No Values Found!" << endl;
                return false;
            }

            Node* temp = tail->next;    //start from head
            do{
                cout << temp->data << " ";
                temp = temp->next;
            }while(temp != tail->next);
            cout << endl;
            return true;
        }

        bool insert(int data){
            if(currSize == size){
                cout << "No more space left" << endl;
                return false;
            }
            Node* temp = new Node(data);
            if(!tail){
                tail = temp;
                temp->next = temp;
                currSize++;
                return true;
            }
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
            currSize++;
            return true;
        }

        bool insertAtMiddle(int data, int element){
            if(currSize == size){
                cout << "No more space left" << endl;
                return false;
            }
            
            if(!tail){
                cout << "Empty Circular Linked List!" << endl;
                return false;
            }

            Node* ptr = tail->next;
            do{
                if(ptr->data == element){
                    Node* temp = new Node(data);
                    temp->next = ptr->next;
                    ptr->next = temp;

                    if(ptr == tail){
                        tail = ptr->next;
                    }
                currSize++;
                return true;
                }
                ptr = ptr->next;
                
            }while(ptr != tail->next);
            
            cout << "Element not found!" << endl;
            return false;
        }

        bool deleteNode(int value){
            if(!tail){
                cout << "Empty Circular Linked List!" << endl;
                return false;
            }
            Node* curr = tail->next;
            Node* prev = tail;
            //for only one element in list
            if(curr->data == value && curr == tail){
                delete curr;
                tail = NULL;
                currSize--;
                return true;
            }
             
            do{
                if(curr->data == value){
                    prev->next = curr->next;
                    if(curr == tail){
                        tail = prev;
                    }
                    delete curr;
                    currSize--;
                    return true;
                }
                prev = curr;
                curr = curr->next;
            }while(curr != tail->next);

            cout << "Element not found!" << endl;
            return false;
        }

        bool isEmpty() const {
            return tail == NULL;
        }

        int getSize() const {
            return currSize;
        }

        bool isFull() const {
            return currSize == size;
        }

        ~CircularLinkedLists() {
            if (tail == NULL) return;
            Node* temp = tail->next;
            cout << "Deleting nodes: ";
            do {
                cout << temp->data << " ";
                Node* next = temp->next;
                delete temp;
                temp = next;
            } while (temp != tail->next);
            cout << endl;
            tail = NULL;
        }  
};
int main() {
    CircularLinkedLists cl(5);
    cl.insert(20);
    cl.insert(40);
    cl.insert(50);
    cl.print();
    cl.insertAtMiddle(30, 20);
    cl.insertAtMiddle(60, 50);
    cl.insertAtMiddle(10, 50);
    cl.print();
    cl.deleteNode(50);
    cl.insert(70);
    cl.print();

    // Edge cases
    cl.deleteNode(20);  // Deleting the head
    cl.deleteNode(70);  // Deleting the tail
    cl.deleteNode(30);  // Deleting from the middle
    cl.print();

    // Emptying the list
    cl.deleteNode(40);
    cl.deleteNode(60);
    cl.print();
    cl.deleteNode(100);  // Attempt to delete from empty list
    return 0;
}
