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

bool detectIntersection(Node* head, Node* head2) {
    if (!head || !head2) {
        return false;
    }

    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    int count2 = 0;
    Node* temp2 = head2;
    while (temp2) {
        count2++;
        temp2 = temp2->next;
    }

    int difference = abs(count - count2);

    temp = head;
    temp2 = head2;

    if (count > count2) {
        while (difference--) {
            temp = temp->next;
        }
    } else {
        while (difference--) {
            temp2 = temp2->next;
        }
    }

    while (temp && temp2) {
        if (temp == temp2) {
            cout << "Intersection found at node with value: " << temp->data << endl;
            return true;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }

    cout << "No intersection found!" << endl;
    return false;
}


int main(){
    Node* head = new Node(10);
    insert(head, 20); insert(head, 30);
    insert(head, 40); insert(head, 50); 
    Node* intersection = insert(head, 60);
    insert(head, 70); insert(head, 80);
    insert(head, 90); insert(head, 100);
   
    Node* head2 = new Node(15);
    insert(head2, 25); 
    Node* temp = insert(head2, 35);
    temp->next = intersection;

    printLoop(head); printLoop(head2);
    
    detectIntersection(head, head2);

}