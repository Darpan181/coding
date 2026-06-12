#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isSymmetricHelp(Node * left , Node * right){
    if(left == nullptr || right == nullptr){
        return left == right;
    }
    if(left->data != right->data) return false;
    return (isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left));
}
bool isSymmetric(Node * root){
    return (root == nullptr) || (isSymmetricHelp(root->left , root->right));
}
int main() {
    Node* root = new Node(1);
    Node* n2_left = new Node(2);
    Node* n2_right = new Node(2);
    Node* n3_left = new Node(3);
    Node* n4_left = new Node(4);
    Node* n4_right = new Node(4);
    Node* n3_right = new Node(3);
    root->left = n2_left;
    root->right = n2_right;
    n2_left->left = n3_left;
    n2_left->right = n4_left;
    n2_right->left = n4_right;
    n2_right->right = n3_right;

    cout<<isSymmetric(root);
return 0;
}