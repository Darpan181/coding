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
int findLeftHeight(Node * root){
    int count = 1;
    while(root){
        count++;
        root = root->left;
    }
    return count;
}
int findRightHeight(Node * root){
    int count = 1;
    while(root){
        count++;
        root = root->right;
    }
    return count;
}
int countNodes(Node * root){
    if(root == nullptr) return 0;

    int count = 0;
    int lh = findLeftHeight(root->left);
    int rh = findRightHeight(root->right);

    if(lh == rh) return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;

    cout<<countNodes(root);
return 0;
}