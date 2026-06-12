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
int maxWidth(Node * root){
    if(root == nullptr) return 0;
    int ans = 0;
    queue<pair<Node *, int>> q; // {node, index}
    q.push({root , 0});
    while(!q.empty()){
        int size = q.size();
        int minIdx = q.front().second; // minm index of a level
        int first , last;
        for(int i=0; i<size; i++){
            int curr_idx = q.front().second - minIdx;
            Node * node = q.front().first;
            q.pop();
            if(i == 0) first = curr_idx;
            if(i == size - 1) last = curr_idx;
            if(node->left) q.push({node->left , curr_idx * 2 + 1});
            if(node->right) q.push({node->right , curr_idx * 2 + 2});
        }
        ans = max(ans , last - first + 1);
    }
    return ans;
}
int main() {
    Node* root = new Node(1);
    Node* n3 = new Node(3);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n4 = new Node(4);
    root->left = n3;
    root->right = n7;
    n3->left = n8;   
    n7->right = n4;  

    cout<<maxWidth(root);
return 0;
}