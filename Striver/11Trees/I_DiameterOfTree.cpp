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
/*.........................BRUTE SOLUTION.....................
int height(Node * root){
    if(root == nullptr) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh , rh);
}
int DiameterTree(Node * root){
    if(root == nullptr) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    int maxi = leftH + rightH;

    int leftDia = DiameterTree(root->left);
    int rightDia = DiameterTree(root->right);
    return max(maxi , max(leftDia , rightDia));
}
*/

//.........................OPTIMAL SOLUTION..........................
int height(Node * root , int &diameter){
    if(root == nullptr) return 0;
    int lh = height(root->left , diameter);
    int rh = height(root->right , diameter);
    diameter = max(diameter , lh + rh);
    return 1 + max(lh , rh);
}
int DiameterTree(Node * root){
    int diameter = 0;
    height(root , diameter);
    return diameter;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->right->right = new Node(7);
    root->right->left->left->left = new Node(9);
    root->right->right->right->right = new Node(8);

    cout<<DiameterTree(root);
return 0;
}