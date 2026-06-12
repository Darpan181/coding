#include<iostream>
#include<vector>
#include<stack>
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
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//................................USING STACK.............................
Node* reverseLLStack(Node* head){
    stack<int> st;
    Node* temp = head;
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
//.............................OPTIMAL SOLUTION.........................
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    Node* front = head;
    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
//.................................BY RECURSION...........................
Node* reverseLLRec(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLLRec(head->next);// break the list into smaller LL
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convert2LL(arr);
    // head = reverseLLStack(head);
    // display(head);

    // head = reverseLL(head);
    // display(head);

    head = reverseLLRec(head);
    display(head);
return 0;
}