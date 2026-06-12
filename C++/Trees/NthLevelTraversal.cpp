#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void NthLevel(Node* root, int curr, int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    NthLevel(root->left, curr+1, level);
    NthLevel(root->right, curr+1, level);
}
int LevelofTree(Node* root){
    if(root==NULL) return 0;
    return 1 + max(LevelofTree(root->left), LevelofTree(root->right));
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    NthLevel(a,1,2);
    cout<<endl;
    cout<<"Level Order Traversal"<<endl;
    for(int i=1; i<=LevelofTree(a); i++){
        NthLevel(a,1,i);
        cout<<endl;
    }
return 0;
}