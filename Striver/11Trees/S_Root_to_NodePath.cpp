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
bool getPath(Node * root, vector<int> &ans, int x){
    if(!root) return false;
    ans.push_back(root->data);
    if(root->data == x){
        return true;
    }
    if(getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}
vector<int> rootToPath(Node * root , int B){
    vector<int> ans;
    if(root == nullptr) return ans;
    getPath(root, ans, B);
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
    n5->left = n6;
    n5->right = n7;

    vector<int> ans = rootToPath(root, 7);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}