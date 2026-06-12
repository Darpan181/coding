/*
    (odd , even) -> element is on left half then, eliminate right half
    (even , odd) -> element is on right half then, eliminate left half
*/
#include<bits/stdc++.h>
using namespace std;
int findSingle(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return 0;
    if(arr[n-1] != arr[n-2]) return n-1;
    int low = 1 , high = n - 2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return mid;
        // left half
        if((mid % 2 == 1 && arr[mid-1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])) low = mid + 1;
        //right half
        else high = mid - 1;
    }
}
int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout<<findSingle(arr);
return 0;
}