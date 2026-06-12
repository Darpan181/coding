#include<bits/stdc++.h>
using namespace std;
//............................MEMOIZATION............................
int findMinEnergy(int idx , vector<int> &arr, vector<int> &dp){
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    int first = findMinEnergy(idx - 1, arr, dp) + abs(arr[idx] - arr[idx - 1]);

    int second = INT_MAX;
    if(idx > 1) second = findMinEnergy(idx - 2, arr, dp) + abs(arr[idx] - arr[idx - 2]);

    return dp[idx] = min(first , second);
}
//.....................TABULATION..................................
int findMinUsingTabulation(int idx, vector<int> &arr){
    int n = arr.size();
    vector<int> dp (n , 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int first = dp[i - 1] + abs(arr[i] - arr[i - 1]);

        int second = INT_MAX;
        if(i > 1) second = dp[i - 2] + abs(arr[i] - arr[i - 2]);

        dp[i] = min(first , second);
    }
    return dp[n - 1];
}

int main(){
    vector<int> arr = {10, 20, 30, 10};
    int n = arr.size();
    vector<int> dp(n , -1);
    // cout<<findMinEnergy(n - 1 , arr, dp);
    cout<<findMinUsingTabulation(n - 1 , arr);
return 0;
}

