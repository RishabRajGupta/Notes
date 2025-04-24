#include <iostream>
using namespace std;

class Node{
    public:
        Node* left;
        int data;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node* node){
    
    if(node == NULL){
        return;
    }
    
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node*node){

    if(node == NULL){
        return;
    }

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node* node){

    if(node == NULL){
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

Node* search(Node* root, int key){

    if(root == NULL || root->data == key){
        return root;
    }
    else if(key < root-> data){
        return search(root->left, key);
    }
    else if(key > root->data){
        return search(root->right, key);
    }

    return root;
}

Node* insert(Node* root, int data){
    
    if(root == NULL){
        return new Node(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    

    return root;
}

Node* inorderSuccesor(Node* node){
    
    Node* temp = node->right;
    
    while(temp->left != NULL){
        temp = temp->left;
    }
    
    return temp;
}

Node* deleteNode(Node* root, int data){
    
    if(root == NULL){
        return root;
    }
    
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else if(data == root->data){
        
        //no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL; 
        }
        //one child
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //two child
        else{
            Node* temp = inorderSuccesor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);

        }
    }
    
    return root;
}

int main(){

    Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 2);
    insert(root, 6);
    insert(root, 14);
    insert(root, 12);
    insert(root, 15);

    inorder(root);
    cout << endl;

    cout << search(root,8) << endl;
    cout << inorderSuccesor(search(root,10))->data << endl;
    deleteNode(root, 14);
    inorder(root);
    cout << endl;

}