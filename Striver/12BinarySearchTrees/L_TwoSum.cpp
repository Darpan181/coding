#include <bits/stdc++.h>
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
class BSTiterator{
    stack<Node *> st;
    // reverse -> true = before
    // reverse -> false = next
    bool reverse = true;
private:
    void pushAll(Node * node){
        for( ; node != nullptr ; ){
            st.push(node);
            if(reverse == true){
                node = node->right;
            }
            else node = node->left;
        }
    }
public:
    BSTiterator(Node * root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node * tempNode = st.top();
        st.pop();
        if(! reverse) pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->data;
    }
};
bool findTarget(Node * root, int k){
    if(!root) return false;
    BSTiterator l(root, false);
    BSTiterator r(root, true);

    int i = l.next();
    int j = r.next();
    while(i < j){
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next(); 
    }
    return false;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    cout<<findTarget(root, 9);
    return 0;
}