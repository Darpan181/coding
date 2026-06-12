#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){ // constructor
        this->val = val;
        this->next = NULL; // by default sb node ke next m NULL aa jaega 
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void size(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout<<count;
    cout<<endl;
}

int main()
{
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;

    // Node* temp = a;
    // while(temp != NULL){
    //     cout<<temp->val<<" ";
    //     temp = temp->next;
    // }
    display(a);
    size(a);
return 0;
}