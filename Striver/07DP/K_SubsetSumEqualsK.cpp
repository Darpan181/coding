#include<bits/stdc++.h>
using namespace std;
//.................................MEMOIZATION.........................................
bool subsetSumEqualK(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
    if(target == 0) return true;
    if(idx == 0) return (arr[0] == target);
    if(dp[idx][target] != -1) return dp[idx][target];

    bool notPick = subsetSumEqualK(arr, idx - 1, target, dp);
    bool pick = false;
    if(target >= arr[idx]){
        pick = subsetSumEqualK(arr, idx - 1, target - arr[idx], dp);
    }

    return dp[idx][target] = (notPick || pick);
}

//..................................TABULATION..........................................
bool subsetSumEqualKTab(vector<int>& arr, int k){
    int n = arr.size();
    vector<vector<bool>> dp(n , vector<bool> (k + 1 , false));

    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target=1; target<=k; target++){
            bool notPick = dp[idx - 1][target];
            bool pick = false;
            if(target >= arr[idx]) pick = dp[idx - 1][target - arr[idx]];
            dp[idx][target] = notPick || pick;
        }
    }
    return dp[n - 1][k];
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int k = 6; 
    int n = arr.size();
    vector<vector<int>> dp(1000 , vector<int> (k + 1 , -1));
    //cout<<subsetSumEqualK(arr , n - 1, k, dp);
    cout<<subsetSumEqualKTab(arr, k);
return 0;
}