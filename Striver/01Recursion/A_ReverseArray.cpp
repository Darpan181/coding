#include<iostream>
using namespace std;

void reverseArr(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverseArr(i+1,arr,n);
}

int main(){
    int arr[] = {2,3,4,5,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArr(0,arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
