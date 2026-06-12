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
void traverse(Node * head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
//...................DIFFERENCE METHOD............................
Node * getIntersection(Node * head1, Node * head2){
    int size1 = 0, size2 = 0;
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1){
        size1++;
        temp1 = temp1->next;
    }
    temp1 = head1;
    while(temp2){
        size2++;
        temp2 = temp2->next;
    }
    temp2 = head2;
    if(size1 >= size2){
        for(int i=1; i<=(size1 - size2); i++){
            temp1 = temp1->next;
        }
    }
    else{
        for(int i=1; i<=(size2 - size1); i++){
            temp2 = temp2->next;
        }
    }
    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}

//.........................OPTIMAL SOLUTION..........................
Node * GetIntersection(Node * head1, Node * head2){
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return temp1; // TC ( O(N1 + N2) )
}
int main(){
    vector<int> arr = {4, 1, 8, 4, 5};
    Node * head1 = convert2LL(arr);
    Node * head2 = new Node(5);
    Node * b2 = new Node(6);
    Node * c2 = new Node(1);
    head2->next = b2; b2->next = c2; c2->next = head1->next->next;
    Node * ans = GetIntersection(head1, head2);
    traverse(ans);
return 0;
}