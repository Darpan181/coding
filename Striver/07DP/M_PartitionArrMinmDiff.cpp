#include<bits/stdc++.h>
using namespace std;
int minmDiff(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    vector<vector<bool>> dp(n , vector<bool> (sum + 1, 0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= sum) dp[0][arr[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target=1; target<=sum; target++){
            bool notPick = dp[idx - 1][target];
            bool pick = false;
            if(arr[idx] <= target) pick = dp[idx - 1][target - arr[idx]];
            dp[idx][target] = notPick || pick;
        }
    }

    // dp[n - 1][col-> 0......sum]
    int mini = INT_MAX;
    for(int s1=0; s1<=sum/2; s1++){
        if(dp[n - 1][s1] == true){
            mini = min(mini , abs((sum - s1) - s1));
        }
    }
    return mini;
}
int main(){
    vector<int> arr = {3, 9, 7, 3};
    cout<<minmDiff(arr);
return 0;
}