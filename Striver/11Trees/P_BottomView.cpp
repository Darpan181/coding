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
vector<int> bottomView(Node * root){
    vector<int> ans;
    if(root == nullptr) return ans;
    map<int, int> mpp; // {line , node}
    queue<pair<Node *, int>> q; // {node , line}
    q.push({root , 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node * node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        if(node->left) q.push({node->left , line - 1});
        if(node->right) q.push({node->right , line + 1});
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
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
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->left = n8;
    n5->right = n9;

    vector<int> ans = bottomView(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
return 0;
}