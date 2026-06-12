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
int MaxPathDown(Node * root , int& maxi){
    if(root == nullptr) return 0;
    int left = max(0 , MaxPathDown(root->left , maxi)); // ignoring negative path
    int right = max(0 , MaxPathDown(root->right , maxi));
    maxi = max(left + right + root->data , maxi);
    return max(left , right) + root->data;
}
int MaximumPathSum(Node * root){
    int maxi = INT_MIN;
    MaxPathDown(root , maxi);
    return maxi;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->right->right = new Node(7);
    root->right->left->left->left = new Node(9);
    root->right->right->right->right = new Node(8);

    cout<<MaximumPathSum(root);
return 0;
}