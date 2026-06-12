#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
Node* RemovefromLast(int idx, Node* head){
    Node* slow = head;
    Node* fast = head;
    // traverse fast to (n+1) steps
    for(int i=1; i<=idx+1; i++){
        if(fast==NULL) return head->next;
        fast = fast->next;
    }
    // move slow and fast at same pace
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    // now the slow is exactly at left of the Nth node from end
    slow->next = slow->next->next;
    return head; 
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    display(a);
    display(RemovefromLast(3,a));
}