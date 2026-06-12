#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int target){
    int low = 0 , high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int upperBound(vector<int> &arr, int target){
    int low = 0 , high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
pair<int, int> FirstandLastPosition(vector<int> &arr, int target){
    int lb = lowerBound(arr, target);
    if(lb == arr.size() || arr[lb] != target) return {-1, -1};
    int ub = upperBound(arr, target);
    return {lb, ub - 1};
}
int main(){
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    pair<int, int> ans = FirstandLastPosition(arr, 8);
    cout<<ans.first<<" "<<ans.second;
return 0;
}