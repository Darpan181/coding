#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int inorderSuccessor(Node * root, int val){
    Node * successor = nullptr;
    while(root != nullptr){
        if(val >= root->data){
            root = root->right;
        }
        else{
            successor = root;
            root = root->left;
        }
    }
    return successor->data;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->left->left->left = new Node(1);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    cout<<inorderSuccessor(root, 8);
return 0;
}