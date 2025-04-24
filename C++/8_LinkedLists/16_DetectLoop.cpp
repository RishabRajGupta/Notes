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

class Node{
    
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &tail){

    if(tail == NULL){
        cout << "Empty!" << endl;
        return;
    }
    
    Node* temp = tail;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);

    cout << endl;
}

//insert (data) after (element) in Linked list
void insert(Node* &tail, int element, int data){
    
    //empty
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;      //circular property
        return;
    }

    //non-empty
    Node* temp = new Node(data);
    
    Node* tracker = tail;
    while(tracker->data != element){
        tracker = tracker->next;
    }

    temp->next = tracker->next;
    tracker->next = temp;
}

//Method 1 - visited vector
bool detectLoop(Node* tail){
    if(!tail || !tail->next){
        return false;
    }
    vector<Node*> visited;
    Node* temp = tail;
    while(temp != NULL){
        for(int i = 0; i < visited.size(); i++){
            if(temp == visited[i]){
                cout << "Loop detected! ";
                return true;
                break;
            }
        }
        visited.push_back(temp);
        temp = temp->next;
    }
    cout << "No Loop detected! ";
    return false;
}

//Method 2 - visited unordered map
bool detectLoop2(Node* tail){
    if(!tail || !tail->next){
        return false;
    }
    unordered_map<Node*, int> visited;
    Node* temp = tail;
    while(temp != NULL){
        if(visited[temp] == 1){
            cout << "Loop detected! ";
            return true;
            break;
        }
        visited[temp] = 1;
        temp = temp->next;
    }
    cout << "No Loop detected! ";
    return false;
}

//Method 3 - Slow & Fast pointers
int detectLoop3(Node* tail){
    if(!tail || !tail->next){
        return 0;
    }

    bool loop = false;
    Node* slow = tail;
    Node* fast = tail->next;
    while(fast && fast->next){
        if(slow == fast){
            cout << "Loop detected! ";
            loop = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(loop){
        int count = 1;
        slow = fast->next;
        while(slow != fast){
            count++;
            slow = slow->next;
        }
        return count;
    }
    cout << "No Loop detected! ";
    return 0;
}

int main() {

    Node* tail = NULL;
    insert(tail, 0, 10);
    insert(tail, 10, 20);
    insert(tail, 20, 30);
    insert(tail, 30, 40);
    insert(tail, 40, 50);
    insert(tail, 50, 60);
    print(tail);
    cout << detectLoop(tail) << endl;
    cout << detectLoop2(tail) << endl;
    cout << detectLoop3(tail) << endl;
    
}