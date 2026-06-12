#include <bits/stdc++.h>
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
vector<vector<int>> verticalTraversal(Node * root){
    map<int, map<int, multiset<int>>> nodes; // vertical, level, multinodes
    queue<pair<Node * , pair<int, int>>> todo; // node, vertical, level
    todo.push({root , {0, 0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node * node = p.first;
        int x = p.second.first , y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left , {x-1 , y+1}});
        }
        if(node->right){
            todo.push({node->right , {x+1 , y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>> ans = verticalTraversal(root);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}