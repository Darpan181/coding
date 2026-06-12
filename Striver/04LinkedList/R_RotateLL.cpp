#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
Node * convert2LL(vector<int> &arr){
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
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
Node * rotateLL(Node * head, int k){
    if(head == nullptr || k == 0) return head;
    int len = 1;
    Node * tail = head;
    while(tail->next != nullptr){
        len++;
        tail = tail->next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    Node * temp = head;
    for(int i=1; i<k; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node * head = convert2LL(arr);
    traverse(head);
    Node * ans = rotateLL(head, 2);
    traverse(ans);
return 0;
}