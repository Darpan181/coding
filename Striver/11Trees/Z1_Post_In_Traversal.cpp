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
Node * buildTreePostIn(vector<int>& inOrder, int inStart, int inEnd, vector<int>& postOrder, int postStart, int postEnd, map<int, int>& inMap){
    if(postStart > postEnd || inStart > inEnd) return nullptr;
    Node * root = new Node(postOrder[postEnd]);
    int inRoot = inMap[postOrder[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePostIn(inOrder, inStart, inRoot - 1, postOrder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreePostIn(inOrder, inRoot + 1, inEnd, postOrder, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}
Node * buildTree(vector<int>& inOrder, vector<int>& postOrder){
    if(inOrder.size() != postOrder.size()) return nullptr;
    map<int, int> inMap;
    for(int i=0; i<inOrder.size(); i++){
        inMap[inOrder[i]] = i;
    }
    return buildTreePostIn(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1, inMap);
}
int main(){
    vector<int> inOrder = {9,3,15,20,7};
    vector<int> postOrder = {9,15,7,20,3};

    Node * ansRoot = buildTree(inOrder, postOrder);
    vector<vector<int>> ans = levelOrderTraversal(ansRoot);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

} 