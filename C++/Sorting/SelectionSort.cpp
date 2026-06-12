#include<iostream>
using namespace std;
int main(){
    int arr[] = {5,3,1,4,2};
    int n = 5;
    for(int i=0; i<n-1; i++){//n-1 passes
        int minidx = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[minidx]){
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
