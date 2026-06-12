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
class BSTiterator{
    stack<Node *> st;
private:
    void pushAll(Node * node){
        for( ; node != nullptr ; st.push(node) , node = node->left);
    }
public:
    BSTiterator(Node * root){
        pushAll(root);
    }
    
    bool hasNext(){
        return !st.empty();
    }

    int next(){
        Node * tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }
};