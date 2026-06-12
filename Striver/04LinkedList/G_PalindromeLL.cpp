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
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//..............................USING STACK............................
bool isPalindromeStk(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    bool flag = true;
    while(temp){
        if(temp->data == st.top()){
            st.pop();
            temp = temp->next;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
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
    return temp;
}
//................................OPTIMAL SOLUTION........................
// 1. find the middle
// 2. reverse the second half
// 3. compare both the halves
// 4. undo the changes made in given LL
bool isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head, *second = newHead;
    while(second != NULL){
        if(first->data != second->data) return false;
        else{
            first = first->next;
            second = second->next;
        }
    }
    return true;
}
int main(){
    vector<int> arr = {1,2,4,3,2,1};
    Node* head = convert2LL(arr);
    cout<<isPalindromeStk(head);
return 0;
}