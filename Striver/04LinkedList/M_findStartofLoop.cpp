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
/*
    Find cycle if exist.
    Move slow back to head.
    Keep fast where it met slow.
    Move both pointers one step at a time.
    The node where they meet again is the start of the cycle.
*/
Node * findCycle(Node * head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node * slow = head;
    Node * fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    n9->next = n3;

    Node * ans = findCycle(n1);
    cout<<ans->data;
return 0;
}