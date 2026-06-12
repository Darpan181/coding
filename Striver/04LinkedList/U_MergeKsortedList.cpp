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
    if(arr.size() == 0) return nullptr;
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
void traverse(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}
Node * mergeLL(Node * head1, Node * head2){
    Node * dummy = new Node(-1);
    Node * temp = dummy;
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->data <= temp2->data){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        else{
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    if(temp1) temp->next = temp1;
    if(temp2) temp->next = temp2;
    return dummy->next;
}
Node * mergeKsortedList(vector<Node * > &list, int k){
    if(k == 0) return nullptr;
    Node * result = list[0];
    for(int i=1; i<k; i++){
        result = mergeLL(result, list[i]);
    }
    return result;
}
int main(){
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 5};
    vector<int> arr3 = {1, 1, 3, 7};
    vector<int> arr4 = {8};
    Node * head1 = convert2LL(arr1);
    Node * head2 = convert2LL(arr2);
    Node * head3 = convert2LL(arr3);
    Node * head4 = convert2LL(arr4);
    vector<Node * > lists = {head1, head2, head3, head4};
    Node * ans = mergeKsortedList(lists, 4);
    traverse(ans);
return 0;
}