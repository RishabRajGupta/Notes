#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


Node* insert(Node* &head, int data) {
    // Create a new node
    Node* temp = new Node(data);

    if (head == NULL) {
        head = temp;
        return temp;
    }


    Node* tracker = head;
    while (tracker->next != NULL) {
        tracker = tracker->next;
    }

    tracker->next = temp;
    return temp;  
}

void printLoop(Node* head){
    Node* temp = head;
    unordered_map<Node*, int> map;
    while(temp){
        cout << temp->data << " ";
        map[temp] += 1;
        if(map[temp] == 3){
            break;
        }
        temp = temp->next;
    }
    cout << endl;
}

int removeLoop(Node* head){
    if(!head || !head->next){
        return 0;
    }

    bool loop = false;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << "Loop detected! ";
            loop = true;
            break;
        }
    }

    if(!loop){
        cout << "No Loop detected! ";
        return 0;
    }

    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return 1;
}

int main(){
    Node* head = new Node(10);
    insert(head, 20); insert(head, 30);
    Node* loopStart = insert(head, 40); 
    insert(head, 50); insert(head, 60); 
    insert(head, 70); insert(head, 80);
    insert(head, 90); insert(head, 100); 
    insert(head, 110);
    Node* last = insert(head, 120);
    last->next = loopStart;
    printLoop(head); removeLoop(head);
    cout << endl; printLoop(head);
}