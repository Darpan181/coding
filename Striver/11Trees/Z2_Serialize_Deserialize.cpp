#include<bits/stdc++.h>
using namespace std; 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * currNode = q.front();
            q.pop();
            if(currNode == nullptr) s.append("null,");
            else s.append(to_string(currNode->val)+',');
            if(currNode != nullptr){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }
TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        if(str == "null" || str.empty()) return nullptr;
        TreeNode * root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();

            if(getline(s, str, ',')){
            if(str == "null"){
                node->left = nullptr;
            }
            else{
                TreeNode * leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            }

            if(getline(s, str, ',')){
            if(str == "null"){
                node->right = nullptr;
            }
            else{
                TreeNode * rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
            }
        }
        return root;
    }