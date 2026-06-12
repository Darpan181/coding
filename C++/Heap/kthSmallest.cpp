#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int arr[] = {10,2,-4,5,18,24,1,-7,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<pq.top();
return 0;
}