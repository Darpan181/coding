#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool subsetSumEqualK(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        if(dp[idx][target] != -1) return dp[idx][target];

        bool notPick = subsetSumEqualK(arr, idx - 1, target, dp);
        bool pick = false;
        if(target >= arr[idx])
            pick = subsetSumEqualK(arr, idx - 1, target - arr[idx], dp);
        return dp[idx][target] = (notPick || pick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(200 , vector<int> (sum/2 + 1 , -1));
        return subsetSumEqualK(nums, nums.size() - 1, sum / 2, dp);
    }
};