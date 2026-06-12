#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
public:
    Node* next;
    int data;
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
Node* add2Num(Node* head1, Node* head2){\
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;
    while(temp1!=NULL || temp2!=NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}
int main(){
    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {3,8,7};
    Node* head1 = convert2LL(arr1);   
    Node* head2 = convert2LL(arr2);
    Node* head3 = add2Num(head1, head2);
    display(head3);
return 0;   
}