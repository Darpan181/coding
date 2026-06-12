#include<bits/stdc++.h>
using namespace std;
// ................................MEMOIZATION.......................................
// int findMaxSumNonAdj(vector<int>& arr, int idx, vector<int>& dp){
//     if(idx == 0) return max(0, arr[idx]);
//     if(idx < 0) return 0;
//     if(dp[idx] != -1) return dp[idx];

//     int pick = arr[idx] + findMaxSumNonAdj(arr, idx - 2, dp);
//     int notPick = 0 + findMaxSumNonAdj(arr, idx - 1, dp);
    
//     return dp[idx] = max(pick, notPick);
// }

//...................................TABULATION....................................
int findMaxSumNonAdj(vector<int>& arr, int n){
    vector<int> dp(n , 0);
    dp[0] = max(0, arr[0]);
    for(int i=1; i<n; i++){
        int pick = arr[i] ; if(i > 1) pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];

        dp[i] = max(pick , notPick);
    }
    return dp[n - 1];
}
int main(){
    vector<int> arr = {2, 7, 9, 3, 1};
    int n = arr.size();
    vector<int> dp(n , -1);
    cout<<findMaxSumNonAdj(arr, n);
return 0;
}