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
int findMaxDistance(map<Node *, Node *> &mpp, Node * target){
    queue<Node *> q;
    q.push(target);
    map<Node *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(mpp[node] && !vis[mpp[node]]){
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(fl) maxi++;
    }
    return maxi;
}
Node * bfsToMapParents(Node * root, map<Node *, Node *> &mpp, int start){
    queue<Node *> q;
    q.push(root);
    Node * res;
    while(!q.empty()){
        Node * node = q.front();
        if(node->data == start) res = node;
        q.pop();
        if(node->left){
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurn(Node * root , int start){
    map<Node *, Node *> mpp;
    Node * target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
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
    n3->left = n5;
    n3->right = n6;
    n4->right = n7;

    cout<<timeToBurn(root, 2);
return 0;
}