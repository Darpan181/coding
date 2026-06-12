#include<iostream>
using namespace std;
#define n 5
class Queue{
public:
    int f;
    int b;
    int arr[n];
    Queue(){// constructor
        f = 0;
        b = 0;
    }
    void push(int val){
        if(b==n){
            cout<<"Queue is FULL!"<<endl;
            return;
        } 
        arr[b] = val;
        b++;
    }
    void pop(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
            }
        return arr[f];
    }
    int back(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
            }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(b-f==0) return true;
        else return false;
    }
    void display(){
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
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
