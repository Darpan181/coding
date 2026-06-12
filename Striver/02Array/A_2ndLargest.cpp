#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,4,7,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int largest = arr[0];
    int secondl = -1;
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            secondl = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondl) secondl = arr[i];
    }
    cout<<largest<<endl;
    cout<<secondl<<endl;
return 0;
}