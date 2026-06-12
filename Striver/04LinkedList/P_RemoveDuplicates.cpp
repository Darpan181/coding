#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * prev;
    Node * next;
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
Node * convert2DLL(vector<int> &arr){
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i=1; i<arr.size(); i++){
        Node * newNode = new Node(arr[i]);
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void traverse(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}
Node * removeDuplicates(Node * head){
    Node * temp = head;
    Node * newNode;
    while(temp != nullptr && temp->next != nullptr){
        newNode = temp->next;
        while(newNode != nullptr && temp->data == newNode->data){
            newNode = newNode->next;
        }
        temp->next = newNode;
        if(newNode) newNode->prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {1, 1, 1, 2, 3, 3, 4};
    Node * head = convert2DLL(arr);
    Node * ans = removeDuplicates(head);
    traverse(ans);
return 0;
}