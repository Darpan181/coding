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
Node * lowestCommonAncestor(Node * root, Node * p, Node * q){
    //base case
    if(root == nullptr || root == p || root == q){
        return root;
    }
    Node * left = lowestCommonAncestor(root->left, p, q);
    Node * right = lowestCommonAncestor(root->right, p, q);

    //result
    if(left == nullptr) return right;
    else if(right == nullptr) return left;
    else return root;
}
int main() {
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n8;
    n3->right = n9;
    n5->left = n6;
    n5->right = n7;

    cout<<lowestCommonAncestor(root, n4, n7)->data;
return 0;
}