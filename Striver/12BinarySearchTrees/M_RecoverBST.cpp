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
vector<vector<int>> levelOrderTraversal(Node * root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            Node * node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
class Solution{
private:
    Node * first;
    Node * prev;
    Node * middle;
    Node * last;
private:
    void inorder(Node * root){
        if(root == nullptr) return;
        inorder(root->left);
        if(prev != nullptr && (root->data < prev->data)){
            // if this is first violation, mark these two nodes as
            // first and middle
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            // if this is 2nd violation, mark this node as last
            else last = root;
        }
        // mark this node as prev
        prev = root;
        inorder(root->right);
    }
public:
    void recoverBST(Node * root){
        first = middle = last = nullptr;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data , last->data);
        else if(first && middle) swap(first->data , middle->data);
    }
};
int main(){
    Node* root = new Node(3);
    Node* n1 = new Node(1);
    Node* n4 = new Node(4);
    Node* n2 = new Node(2);
    root->left = n1;
    root->right = n4;
    n4->left = n2;

    Solution obj;
    obj.recoverBST(root);
    vector<vector<int>> ans = levelOrderTraversal(root);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}