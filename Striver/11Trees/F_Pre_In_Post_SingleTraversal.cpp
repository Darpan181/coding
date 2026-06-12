/*
store (node , num) in stack
if num == 1 -> preorder ; num++ ; left;
if num == 2 -> inorder ; num++ ; right;
if num == 3 -> postorder  
*/
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
vector<vector<int>> preInPostTraversal(Node * root){
    if(root == nullptr) return {};
    stack<pair<Node * , int>> st;
    st.push({root, 1});
    vector<int> pre , in , post;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != nullptr){
                st.push({it.first->left , 1});
            }
        }
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != nullptr){
                st.push({it.first->right , 1});
            }
        }
        else post.push_back(it.first->data);
    }
    return {pre, in, post}; 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    vector<vector<int>> result = preInPostTraversal(root);
    cout << "Preorder: ";
    for(int x : result[0]) cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for(int x : result[1]) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for(int x : result[2]) cout << x << " ";
    cout << endl;
}