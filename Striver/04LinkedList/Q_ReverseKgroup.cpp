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
void reverseLL(Node * head){
    Node * temp = head;
    Node * prev = nullptr;
    Node * front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return;
}
Node * getKthNode(Node * temp, int k){
    k -= 1;
    while(temp != nullptr && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}
Node * reverseKgroup(Node * head, int k){
    Node * temp = head;
    Node * prevLast = nullptr;
    while(temp != nullptr){
        Node * kthNode = getKthNode(temp, k);
        if(kthNode == nullptr){
            if(prevLast) prevLast->next = temp;
            break;
        }
        Node * nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head) head = kthNode;
        else prevLast->next = kthNode;

        prevLast = temp;
        temp = nextNode;
    }
    return head; 
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node * head = convert2LL(arr);
    traverse(head);
    head = reverseKgroup(head, 3);
    traverse(head);
return 0;
}