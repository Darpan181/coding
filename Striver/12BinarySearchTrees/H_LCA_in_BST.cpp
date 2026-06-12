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
Node * lowestCommonAncestor(Node * root, Node * p, Node * q){
    if(root == nullptr) return nullptr;
    Node * curr = root;
    if(root->data < p->data && root->data < q->data){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(root->data > p->data && root->data > q->data){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}
int main(){
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    cout<<lowestCommonAncestor(root, root->left, root->right)->data; // 2 , 8
return 0;
}