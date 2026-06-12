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
    if(arr.empty()) return nullptr;
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
Node * deleteAllOccurences(Node * head, int target){
    Node * temp = head;
    Node * prevNode;
    Node * nextNode;
    while(temp != nullptr){
        if(temp->data == target){
        if(temp == head) head = head->next;
        nextNode = temp->next;
        prevNode = temp->prev;
        if(nextNode) nextNode->prev = prevNode;
        if(prevNode) prevNode->next = nextNode;
        delete temp;
        temp = nextNode;
        }
        else
            temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    Node * head = convert2DLL(arr);
    traverse(head);
    Node * ans = deleteAllOccurences(head, 10);
    traverse(head);
return 0;
}