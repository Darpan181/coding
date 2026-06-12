//  0 to Low-1  ->  0
//  Low to mid-1   -> 1
//  High+1 to n-1    -> 2
#include<iostream>
using namespace std;
int main(){
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}