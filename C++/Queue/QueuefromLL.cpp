#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class Queue{
public:
    Node* head;
    Node* tail;
    int s;
    Queue(){
        head = tail = NULL;
        s = 0;
    }
    void push(int val){
        Node* temp = new Node(val);
        if(s==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"Queue is EMPTY!";
            return;
        }
        head = head->next;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is EMPTY!";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Queue is EMPTY!";
            return -1;
        }
        return tail->val;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        else return false;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
return 0;
}