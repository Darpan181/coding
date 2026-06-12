#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int findFloor(Node * root, int key){
    int floor = -1;
    while(root){
        if(key == root->data){
            floor = root->data;
            return floor;
        }
        if(key > root->data){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}
int main(){
    Node* root = new Node(10);
    Node* n5 = new Node(5);
    Node* n15 = new Node(15);
    Node* n2 = new Node(2);
    Node* n6 = new Node(6);
    root->left = n5;
    root->right = n15;
    n5->left = n2;
    n5->right = n6;

    cout<<findFloor(root, 7);
return 0;
}