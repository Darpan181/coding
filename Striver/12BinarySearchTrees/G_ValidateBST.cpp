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
bool find(Node * root, int minVal, int maxVal){
    if(root == nullptr) return true;
    if(root->data < minVal || root->data > maxVal) return false;
    return find(root->left, minVal, root->data) && find(root->right, root->data, maxVal);
}
bool ValidateBST(Node * root){
    return find(root, INT_MIN, INT_MAX);
}
int main(){
    Node* root = new Node(5);
    Node* n1 = new Node(1);
    Node* n4 = new Node(4);
    Node* n3 = new Node(3);
    Node* n6 = new Node(6);
    root->left = n1;
    root->right = n4;
    n4->left = n3;
    n4->right = n6;

    cout<<ValidateBST(root);
return 0;
}