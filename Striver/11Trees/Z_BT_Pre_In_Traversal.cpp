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
Node * buildTreePreIn(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int>& inMap){
    if(preStart > preEnd || inStart > inEnd) return nullptr;
    Node * root = new Node(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreePreIn(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inMap);
    root->right = buildTreePreIn(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);
    return root;
}
Node * buildTree(vector<int>& preOrder , vector<int>& inOrder){
    map<int, int> inMap; // {node, index} (index in inOrder)
    
    // make a hash table for these nodes
    for(int i=0; i<inOrder.size(); i++){
        inMap[inOrder[i]] = i;
    }
    Node * root = buildTreePreIn(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return root;
}
int main(){
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    Node * ansRoot = buildTree(preOrder , inOrder);
    vector<vector<int>> ans = levelOrderTraversal(ansRoot);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}