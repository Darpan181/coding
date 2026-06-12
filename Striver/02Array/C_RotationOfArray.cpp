// #include<iostream>
// using namespace std;

// void leftRotate(int arr[], int n, int d){
//     int temp[d];
//     for(int i=0; i<d; i++){
//         temp[i] = arr[i];
//     }
//     for(int i=d; i<n; i++){
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d; i<n; i++){
//         arr[i] = temp[i-(n-d)];
//     }
// }

// int main(){
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int d = 3;
//     leftRotate(arr,n,d);
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }

#include<iostream>
using namespace std;

void reverseArr(int arr[], int start, int end){
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
    reverseArr(arr,0,d-1);
    reverseArr(arr,d,n-1);
    reverseArr(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}