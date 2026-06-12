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
void find(Node * root, int& k, int& ans){
    if(root == nullptr) return;
    find(root->left, k, ans);
    k--;
    if(k == 0){
        ans = root->data;
        return;
    }
    find(root->right, k, ans);
}
int kthSmallest(Node * root, int k){
    int ans = -1;
    find(root, k, ans);
    return ans;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    cout<<kthSmallest(root, 3);
return 0;
}