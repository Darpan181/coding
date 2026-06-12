/*
Self Notes:
🍋 Mark each node to its parent to traverse upwards
🍋 We will do a BFS traversal starting from the target node
🍋 As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
🍋 when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void markParents(Node * root, unordered_map<Node *, Node *> &parent_track, Node * target){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}
vector<int> distanceK(Node * root, Node * target, int k){
    unordered_map<Node *, Node *> parent_track; // node -> parent
    markParents(root, parent_track, target);

    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    // 2nd BFS to go up to K level from target node and using our hashtable info
    while(!q.empty()){
        int size = q.size();
        if(curr_level == k) break;
        for(int i=0; i<size; i++){
            Node * current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
        curr_level++;
    }
    vector<int> res;
    while(!q.empty()){
        Node * current = q.front();
        q.pop();
        res.push_back(current->data);
    }
    return res;
}
int main() {
    Node* root = new Node(3);
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n6 = new Node(6);
    Node* n2 = new Node(2);
    Node* n0 = new Node(0);
    Node* n8 = new Node(8);
    Node* n7 = new Node(7);
    Node* n4 = new Node(4);
    root->left = n5;
    root->right = n1;
    n5->left = n6;
    n5->right = n2;
    n1->left = n0;
    n1->right = n8;
    n2->left = n7;
    n2->right = n4;

    vector<int> ans = distanceK(root, n5, 2);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}