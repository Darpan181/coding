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
/*.........................BRUTE SOLUTION
int maxHeight(Node * root){
    if(root == nullptr) return 0;
    int left = maxHeight(root->left);
    int right = maxHeight(root->right);
    return 1 + max(left, right);
}
bool checkBalanced(Node * root){
    if(root == nullptr) return true;
    int leftH = maxHeight(root->left);
    int rightH = maxHeight(root->right);
    if(abs(leftH - rightH) > 1) return false;

    bool left = checkBalanced(root->left);
    bool right = checkBalanced(root->right);
    if(!left || !right) return false;
    return true;
}
*/
//..........................OPTIMAL SOLUTION..........................
int height(Node * root){
    if(root == nullptr) return 0;
    int left = height(root->left);
    if(left == -1) return -1;

    int right = height(root->right);
    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}
bool checkBalanced(Node * root){
    if(height(root) == -1) return false;
    else return true;
}
int main(){
Node* root = new Node(3);
root->left = new Node(9);
root->right = new Node(20);
root->right->left = new Node(15);
root->right->right = new Node(7);

    cout<<checkBalanced(root);    
return 0;
}