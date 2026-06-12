#include<bits/stdc++.h>
using namespace std;
int maxList(vector<int> &arr){
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxEle = max(arr[i], maxEle);
    }
    return maxEle;
}
long long length(vector<int> &arr, int num){
    long long len = 0;
    for(int i=0; i<arr.size(); i++){
        len += (arr[i] + num - 1) / num; // finding ceil value
    }
    return len;
}
int smallestDivisor(vector<int> &nums, int threshold){
    int ans;
    int low = 1 , high = maxList(nums);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(length(nums, mid) <= threshold){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout<<smallestDivisor(nums, threshold);
return 0;
}