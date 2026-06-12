#include<iostream>
using namespace std;
void printMax(int arr[],int n, int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    }
    if(arr[idx]>max) max = arr[idx];
    printMax(arr,n,idx+1,max);
}
int main(){
    int arr[] = {2,7,5,8,3,9,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMax(arr,n,0,INT32_MIN);
return 0;
}