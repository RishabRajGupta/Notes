#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int value) {
        data = value;
        next = NULL;
        random = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Value: " << temp->data;
        if (temp->random)
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
    cout << "\n";
}

void insertAtEnd(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

//My Solution
Node* CloneLinkedList(Node *head) {
    if(!head) return head;
    Node* h1 = head;
    Node* result = new Node(0);
    Node* curr = result;
    while(h1){
        Node* temp = new Node(h1->data);
        curr->next = temp;
        h1 = h1->next;
        curr = temp;
    }

    h1 = head;
    Node *h2 = result->next;
    Node* track1 = head;
    Node* track2 = result->next;
    
    while(track1){
        if(track1->random){
            while(h1 != track1->random && h1){
                h1 = h1->next;
                h2 = h2->next;
            }
            track2->random = h2;
        }
        track1 = track1->next;
        track2 = track2->next;
        h1 = head;
        h2 = result->next;
    }
    
    
    return result->next;
}

//coder army
Node* cloneLinkedList(Node* head){
    if(!head) return head;
    
    Node* headcopy = new Node(0);
    Node* tailcopy = headcopy;
    Node* temp = head;
    
    while(temp){
        tailcopy->next = new Node(temp->data);
        tailcopy = tailcopy->next;
        temp = temp->next;
    }

    tailcopy = headcopy;
    headcopy = headcopy->next;
    delete tailcopy;

    tailcopy = headcopy;
    temp = head;
    unordered_map<Node*, Node*> m;

    while(temp){
        m[temp] = tailcopy;
        temp = temp->next;
        tailcopy = tailcopy->next;
    }

    temp = head;
    tailcopy = headcopy;
    while(temp){
        if(temp->random){
            tailcopy->random = m[temp->random];
        }
        tailcopy = tailcopy->next;
        temp = temp->next;
    }

    return headcopy;
}

//coder army 2
Node* cloneLinkedList2(Node* head) {
    if (!head) return nullptr;

    // Insert cloned nodes after original nodes
    Node* curr1 = head;
    while (curr1) {
        Node* copy = new Node(curr1->data);
        copy->next = curr1->next;
        curr1->next = copy;
        curr1 = copy->next;
    }

    // Assign random pointers to the cloned nodes
    curr1 = head;
    while (curr1) {
        if (curr1->random) {
            curr1->next->random = curr1->random->next;
        }
        curr1 = curr1->next->next;
    }

    Node* dummy = new Node(0);
    Node* cloneTail = dummy;
    curr1 = head;

    while (curr1) {
        Node* copy = curr1->next;
        curr1->next = copy->next;
        cloneTail->next = copy;
        cloneTail = cloneTail->next;

        curr1 = curr1->next;
    }

    return dummy->next;
}


int main() {
    // 1 -> 2 -> 3 -> 4
    Node* head1 = NULL, *tail1 = NULL;
    insertAtEnd(head1, tail1, 1);
    insertAtEnd(head1, tail1, 2);
    insertAtEnd(head1, tail1, 3);
    insertAtEnd(head1, tail1, 4);
    
    head1->random = head1->next->next; // 1 -> 3
    head1->next->random = head1; // 2 -> 1
    head1->next->next->random = head1->next->next->next; // 3 -> 4
    head1->next->next->next->random = head1->next; // 4 -> 2

    printList(head1);
    

    Node* clonedList = cloneLinkedList2(head1);
    printList(clonedList);
}
