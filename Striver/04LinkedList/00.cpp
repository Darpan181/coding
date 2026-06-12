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
    if(arr.size() == 0) return nullptr;
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
Node * findMiddle(Node * head){
    Node * slow = head , * fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node * merge(Node * head1 , Node * head2){
    Node * dummy = new Node(-1);
    Node * temp = dummy;
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        else{
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    if(temp1) temp->next = temp1;
    if(temp2) temp->next = temp2;
    return dummy->next;
}
Node * sortLL(Node * head){
    Node * middle = findMiddle(head);
    if(head == nullptr || head->next == nullptr) return head;
    Node * temp1 = head;
    Node * temp2 = middle->next;
    middle->next = nullptr;
    temp1 = sortLL(temp1);
    temp2 = sortLL(temp2);
    return merge(temp1, temp2);
}
int main(){
    vector<int> arr = {4, 1, 3, 5, 2};
    Node * head = convert2LL(arr);
    Node * ans = sortLL(head);
    traverse(ans);
return 0;
}