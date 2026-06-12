#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* convert2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front = head;
    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* add1toLL(Node* head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    int sum = 0;
    while(temp != NULL){
        sum = carry + temp->data;
        temp->data = sum % 10;
        carry = sum / 10;
        temp = temp->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return reverseLL(head);
}
int main(){
    vector<int> arr = {9,9,9};
    Node* head = convert2LL(arr);
    head = add1toLL(head);
    display(head);
return 0;
}