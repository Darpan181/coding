#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr , int x){
    int ans = arr.size();
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1; 
    }
    return ans;
}
int upperBound(vector<int> &arr , int x){
    int ans = arr.size();
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1; 
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int lb = lowerBound(arr, 9); // arr[idx] >= x ; smallest -> idx
    cout<<lb<<endl;

    int ub = upperBound(arr, 5); // arr[idx] > x ; smallest -> idx
    cout<<ub;
return 0;
}