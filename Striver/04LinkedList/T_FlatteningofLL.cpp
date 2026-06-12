#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node * bottom;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->bottom = nullptr;
    }
};
void traverse(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->bottom;
    }
    cout<<endl;
    return;
}
Node * mergeLL(Node * head1, Node * head2){
    Node * dummy = new Node(-1);
    Node * temp = dummy;
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->data <= temp2->data){
            temp->bottom = temp1;
            temp1 = temp1->bottom;
            temp = temp->bottom;
        }
        else{
            temp->bottom = temp2;
            temp2 = temp2->bottom;
            temp = temp->bottom;
        }
        temp->next = nullptr; 
    }
    if(temp1) temp->bottom = temp1;
    if(temp2) temp->bottom = temp2;
    return dummy->bottom;
}
Node * flattenLL(Node * head){
    if(head == nullptr || head->next == nullptr) return head;
    Node * mergeHead = flattenLL(head->next);
    head = mergeLL(head, mergeHead);
    return head;
}
int main(){
    // main list
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    // bottom list of 5 : 7->8->30
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    // bottom list of 10 : 20
    head->next->bottom = new Node(20);

    // bottom list of 19 : 22->50
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    // bottom list of 28 : 35->40
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);

    Node * ans = flattenLL(head);
    traverse(ans);
return 0;
}