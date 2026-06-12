// right view : last node of every level is my answer
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
void recursion(Node * root , int level , vector<int> &ans){
    if(root == nullptr) return;
    if(ans.size() == level) ans.push_back(root->data);
    recursion(root->right , level + 1 , ans);
    recursion(root->left , level + 1 , ans);
}
vector<int> rightView(Node * root){
    vector<int> ans;
    recursion(root , 0 , ans);
    return ans;
}
int main() {
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n7;
    n5->left = n6;

    vector<int> ans = rightView(root);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}