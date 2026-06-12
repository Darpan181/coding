#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * prev;
    Node * next;
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
Node * convert2DLL(vector<int> &arr){
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i=1; i<arr.size(); i++){
        Node * newNode = new Node(arr[i]);
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
vector<pair<int, int>> pairsWithGivenSum(Node * head, int target){
    vector<pair<int, int>> result;
    Node * back = head;
    while(back->next != nullptr){
        back = back->next;
    }
    Node * front = head;
    while(front != nullptr && back != nullptr && front != back && front->prev != back){
        if(front->data + back->data > target) back = back->prev;
        else if(front->data + back->data < target) front = front->next;
        else{
            result.push_back({front->data, back->data});
            front = front->next;
            back = back->prev;
        }
    }
    return result;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 9};
    Node * head = convert2DLL(arr);
    vector<pair<int, int>> ans = pairsWithGivenSum(head, 5);
    for(auto it : ans){
        cout<<"("<<it.first<<","<<it.second<<")"<<endl;
    }
return 0;
}