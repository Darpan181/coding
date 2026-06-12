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
Node* OddEvenLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* tempOdd = head;
    Node* tempEven = head->next;
    Node* link = tempEven; 
    while(tempEven!=NULL && tempEven->next != NULL){
        tempOdd->next = tempOdd->next->next;
        tempOdd = tempOdd->next;
        tempEven->next = tempEven->next->next;
        tempEven = tempEven->next;
    }
    tempOdd->next = link;
    return head;
}
int main(){
    vector<int> arr = {2,1,3,5,6,4};
    Node* head = convert2LL(arr);
    Node* head1 = OddEvenLL(head);
    display(head1);
return 0;
}