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
bool isIdentical(Node * root1 , Node * root2){
    if(root1 == nullptr || root2 == nullptr) return ( root1 == root2 );
    return (root1->data == root2->data) && isIdentical(root1->left , root2->left) && isIdentical(root1->right , root2->right);
}
int main(){
    // Tree p
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    // Tree q
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    cout<<isIdentical(p , q);
return 0;
}