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
Node * findLastRight(Node * root){
    if(root->right == nullptr) return root;
    return findLastRight(root->right);
}
Node * helper(Node * root){
    if(root->left == nullptr) return root->right;
    else if(root->right == nullptr) return root->left;
    Node * rightChild = root->right;
    Node * lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
Node * deleteInBST(Node * root, int key){
    if(root == nullptr) return nullptr;
    if(root->data == key) return helper(root);
    Node * dummy = root;
    while(root != nullptr){
        if(root->data > key){
            if(root->left != nullptr && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != nullptr && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }
    return dummy;
}
int main(){
    Node* root = new Node(5);
    Node* n3 = new Node(3);
    Node* n6 = new Node(6);
    Node* n2 = new Node(2);
    Node* n4 = new Node(4);
    Node* n7 = new Node(7);
    root->left = n3;
    root->right = n6;
    n3->left = n2;
    n3->right = n4;
    n6->right = n7;

    Node * newTree = deleteInBST(root, 3);
    vector<vector<int>> ans = levelOrderTraversal(newTree);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}