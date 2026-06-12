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
int findCeil(Node * root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
int main(){
    Node* root = new Node(10);
    Node* n5 = new Node(5);
    Node* n13 = new Node(13);
    Node* n3 = new Node(3);
    Node* n6 = new Node(6);
    Node* n11 = new Node(11);
    Node* n14 = new Node(14);
    Node* n2 = new Node(2);
    Node* n4 = new Node(4);
    Node* n9 = new Node(9);
    root->left = n5;
    root->right = n13;
    n5->left = n3;
    n5->right = n6;
    n13->left = n11;
    n13->right = n14;
    n3->left = n2;
    n3->right = n4;
    n6->right = n9;

    cout<<findCeil(root, 8);
return 0;
}