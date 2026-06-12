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
//...........................BRUTE SOLUTION........................
Node* remove(Node* head, int n){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    if(count == n) return head->next;
    temp = head;
    int del = count - n - 1;
    for(int i=1; i<=del; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
//...................................OPTIMAL SOLUTION.....................
Node* removeFromLast(Node* head, int n){
    Node* fast = head;
    for(int i=1; i<=n; i++){
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    Node* slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convert2LL(arr);
    // head = remove(head,4);
    // display(head);
    head = removeFromLast(head,5);
    display(head);
return 0;
}