#include<bits/stdc++.h>
using namespace std;
int searchInRotatedArr(vector<int> &arr , int x){
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) return mid;
        
        /*
        if array contain duplicate elements
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        */

        // left sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        } 
        //right sorted
        else{
            if(arr[mid] <= x && x <= arr[high]) low = mid + 1;
            else high = mid - 1; 
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout<<searchInRotatedArr(arr, 1);
return 0;
}