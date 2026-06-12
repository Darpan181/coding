#include<bits/stdc++.h>
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
Node * insertIntoBST(Node * root, int val){
    if(root == nullptr) return new Node(val);
    Node * curr = root;
    while(true){
        if(curr->data <= val){
            if(curr->right != nullptr) curr = curr->right;
            else{
                curr->right = new Node(val);
                break;
            }
        }
        else{
            if(curr->left != nullptr) curr = curr->left;
            else{
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}
int main(){
    Node* root = new Node(4);
    Node* n2 = new Node(2);
    Node* n7 = new Node(7);
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    root->left = n2;
    root->right = n7;
    n2->left = n1;
    n2->right = n3;

    Node * newTree = insertIntoBST(root, 5);
    vector<vector<int>> ans = levelOrderTraversal(newTree);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}