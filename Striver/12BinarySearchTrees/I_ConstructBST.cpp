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
Node * build(vector<int>& preorder, int& i, int bound){ // upper bound
    if(i == preorder.size() || preorder[i] > bound) return nullptr;
    Node * root = new Node(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);
    return root;
}
Node * bstFromPreorder(vector<int>& preorder){
    int i = 0;
    return build(preorder, i, INT_MAX);
}
int main(){
    vector<int> preOrder = {8,5,1,7,10,12};
    Node * ansRoot = bstFromPreorder(preOrder);
    vector<vector<int>> ans = levelOrderTraversal(ansRoot);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}