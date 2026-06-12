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

int width(Node * root){
    if(root == nullptr) return 0;
    queue<pair<Node * , int>> q;
    q.push({root , 0});
    int ans = 0;

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first , last;

        for(int i=0; i<size; i++){
            Node * node = q.front().first;
            int currID = q.front().second;
            q.pop();

            if(i == 0) first = currID;
            if(i == size - 1) last = currID;

            if(node->left) q.push({node->left , 2 * currID + 1});
            if(node->right) q.push({node->right , 2 * currID + 2});
        }
        ans = max(ans , last - first + 1);
    }
    return ans;
}

int main(){
Node* root = new Node(1);

root->left = new Node(3);
root->right = new Node(2);

root->left->left = new Node(5);

root->right->right = new Node(9);

root->left->left->left = new Node(6);

root->right->right->left = new Node(7);

    cout<<width(root);

return 0;
}