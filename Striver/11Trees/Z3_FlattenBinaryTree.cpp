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
/*
void flattenBT(Node * root){
    stack<Node *> st;
    st.push(root);
    while(!st.empty()){
        Node * curr = st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
        if(!st.empty()) curr->right = st.top();
        curr->left = nullptr;
    }
}
*/

//..............................OPTIMAL SOLUTION...............................
void flattenBT(Node * root){
    if(root == nullptr) return;
    Node * curr = root;
    Node * prev = nullptr;
    while(curr != nullptr){
        if(curr->left != nullptr){
            prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
    return;
}
int main(){
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n5 = new Node(5);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    root->left = n2;
    root->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;
    n6->left = n7;

    flattenBT(root);
    while(root){
        cout<<root->data<<" ";
        root = root->right;
    }
return 0;
}