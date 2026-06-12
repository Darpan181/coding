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
Node * searchBST(Node * root, int val){
    while(root != nullptr && root->data != val){
        root = root->data > val ? root->left : root->right;
    }
    return root;
}
int main() {
    Node* root = new Node(4);
    Node* n2 = new Node(2);
    Node* n7 = new Node(7);
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    root->left = n2;
    root->right = n7;
    n2->left = n1;
    n2->right = n3;

    cout<<searchBST(root, 7)->data;
return 0;
}