#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node * next;
    Node * random;
    Node(int data){
        this->val = val;
        this->next = nullptr;
        this->random = nullptr;
    }
};
Node* copyRandomList(Node* head) {
        Node * temp = head;
        while(temp != nullptr){ // insert in between
            Node * copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        // connect the random pointers
        temp = head;
        while(temp != nullptr){
            Node * copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = nullptr;
            temp = temp->next->next;
        }
        // connect next pointer
        Node * dummy = new Node(-1);
        Node * res = dummy;
        temp = head;
        while(temp != nullptr){
            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }