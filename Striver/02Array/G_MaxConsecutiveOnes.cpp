#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,1,0,1,1,1,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxi = 0, count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==1) count++;
        else{
            if(maxi<count) maxi = count;
            count = 0;
        }
    }
    cout<<maxi;
return 0;
}