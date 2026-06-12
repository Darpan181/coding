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
int findLength(Node * slow){
    int count = 1;
    Node * temp = slow->next;
    while(temp != slow){
        count++;
        temp = temp->next;
    }
    return count;
}
int countLoopLength(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow);
    }
    return 0;
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

    cout<<countLoopLength(n1);
return 0;
}