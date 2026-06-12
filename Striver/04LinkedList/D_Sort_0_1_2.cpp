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
Node* sort012(Node* head){
    Node* dummyZero = new Node(-1);
    Node* dummyOne = new Node(-1);
    Node* dummyTwo = new Node(-1);
    Node* temp0 = dummyZero;
    Node* temp1 = dummyOne;
    Node* temp2 = dummyTwo;
    while(head != NULL){
        if(head->data == 0){
            temp0->next = head;
            temp0 = temp0->next;
        }
        else if(head->data == 1){
            temp1->next = head;
            temp1 = temp1->next;
        }
        else{
            temp2->next = head;
            temp2 = temp2->next;
        }
        head = head->next;
    }
    temp2->next = NULL;
    temp0->next = dummyOne->next;
    temp1->next = dummyTwo->next;
    return dummyZero->next;
}
int main(){
    vector<int> arr = {2, 1, 0, 2, 0, 1, 2};
    Node* head = convert2LL(arr);
    head = sort012(head);
    display(head);
}