/*
Boundary Traversal : 
1. left boundary excluding leaf nodes
2. leaf nodes
3. right boundary (in reverse) excluding leaf
*/
#include <bits/stdc++.h>
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
bool isLeaf(Node * root){
    if(root != nullptr && root->left == nullptr && root->right == nullptr) return true;
    return false;
}
void leftBoundary(Node * root , vector<int> &ans){
    Node * curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void rightBoundary(Node * root , vector<int> &ans){
    vector<int> temp;
    Node * curr = root->right;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}
void leaves(Node * root , vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) leaves(root->left , ans);
    if(root->right) leaves(root->right , ans);
}
vector<int> boundaryTraversal(Node * root){
    vector<int> ans;
    if(root == nullptr) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root, ans);
    leaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->right->right = new Node(8);
    root->left->left->right = new Node(4);
    root->right->right->left = new Node(9);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);
    
    vector<int> ans = boundaryTraversal(root);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}