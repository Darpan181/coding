#include<bits/stdc++.h>
using namespace std;
int maxList(vector<int> &arr){
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxEle = max(arr[i], maxEle);
    }
return maxEle;
}
long long listSum(vector<int> &arr){
    long long sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
return sum;
}
int CountSubArr(vector<int> &arr, int partition){
    int nop = 1 , subArrSum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] + subArrSum <= partition){
            subArrSum += arr[i];
        }
        else{
            nop++;
            subArrSum = arr[i];
        }
    }
return nop;
}
int splitArray(vector<int>& nums, int k) {
    int low = maxList(nums) , high = listSum(nums);
    int ans = high;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(CountSubArr(nums, mid) <= k){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
return ans;
}
int main(){
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout<<splitArray(nums, k);
return 0;
}