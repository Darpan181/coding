#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
public:
    Node* back;
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};
Node* convert2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
        temp->back = prev;
        prev = temp;
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
Node* reverseStack(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convert2DLL(arr);
    display(head);
    head = reverseStack(head);
    display(head);
return 0;
}