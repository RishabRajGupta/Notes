#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a new node at the end of a linked list
void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* merge(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node* h1 = head1;
    Node* h2 = head2;
    Node* root = new Node(0);
    Node* curr = root;
    while(h1 && h2){
        if(h1->data <= h2->data){
            curr->next = h1;
            h1 = h1->next;
        }
        else{
            curr->next = h2;
            h2 = h2->next;
        }
        curr = curr->next;
    }
    curr->next = (h1) ? h1 : h2;
    return root->next;
}

void mergeLL(vector<Node*> &arr, int start, int end){

    if(start >= end){
        return;
    }

    int mid = (start+end)/2;
    mergeLL(arr, start, mid);
    mergeLL(arr, mid+1, end);

    arr[start] = merge(arr[start], arr[mid+1]);
}


int main() {
    int k = 3;
    vector<Node*> arr(k);

    // Test Case 1
    Node* head1 = new Node(1);
    Node* tail1 = head1;
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);

    Node* head2 = new Node(1);
    Node* tail2 = head2;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);

    Node* head3 = new Node(2);
    Node* tail3 = head3;
    insertAtTail(tail3, 6);

    arr[0] = head1;
    arr[1] = head2;
    arr[2] = head3;

    for (int i = 0; i < k; i++) {
        printList(arr[i]);
    }   cout << endl;

    mergeLL(arr, 0, 2);
    printList(arr[0]);

    cout << endl;

    // Test Case 2
    k = 4;
    vector<Node*> arr2(k);

    Node* head4 = new Node(2);
    Node* tail4 = head4;
    insertAtTail(tail4, 7);
    insertAtTail(tail4, 10);

    Node* head5 = new Node(1);
    Node* tail5 = head5;
    insertAtTail(tail5, 8);
    insertAtTail(tail5, 9);

    Node* head6 = new Node(3);
    Node* tail6 = head6;
    insertAtTail(tail6, 6);
    insertAtTail(tail6, 12);

    Node* head7 = new Node(5);
    Node* tail7 = head7;
    insertAtTail(tail7, 11);
    insertAtTail(tail7, 15);

    arr2[0] = head4;
    arr2[1] = head5;
    arr2[2] = head6;
    arr2[3] = head7;

    for (int i = 0; i < k; i++) {
        printList(arr2[i]);
    }   cout << endl;

    mergeLL(arr2, 0, 3);
    printList(arr2[0]);

    cout << endl;
    return 0;
}
