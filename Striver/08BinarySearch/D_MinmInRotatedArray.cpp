// sorted part may or may not contain the minimum
#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &arr){
    int low = 0 , high = arr.size() - 1;
    int minm = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        // left sorted
        if(arr[low] <= arr[mid]){
            minm = min(minm , arr[low]);
            low = mid + 1;
        }
        // right sorted
        else{
            minm = min(minm , arr[high]);
            high = mid - 1;
        }
    }
    return minm;
}
int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 4, 5, 6};
    cout<<findMin(arr);
return 0;
}