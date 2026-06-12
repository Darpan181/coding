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
bool detectLoop(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node * head = convert2LL(arr);
    cout<<detectLoop(head);
return 0;
}