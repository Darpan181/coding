#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> mpq; //Min-Heap
    priority_queue<int> pq;// by default Max-Heap
    pq.push(10);
    pq.push(19);
    pq.push(23);
    pq.push(45);
    cout<<pq.top()<<endl;// max element: 45
    pq.pop();
    cout<<pq.top()<<endl;
return 0;
}