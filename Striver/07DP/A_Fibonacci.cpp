#include<bits/stdc++.h>
using namespace std;
// ..........................MEMOIZATION................................
int fibo(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp); // TC : O(N)
}                                                     // SC : O(N)
int main(){
    int n = 8;
    vector<int> dp(n + 1, -1);
    cout<<fibo(n, dp);
return 0;
}

// ............................TABULATION...............................
// int main(){
//     int n = 5;
//     int prev2 = 0;
//     int prev = 1;
//     int curr;
//     for(int i=2; i<=n; i++){
//         curr = prev + prev2;
//         prev2 = prev;
//         prev = curr;
//     }
//     cout<<prev; // TC : O(N) , SC : O(1)
// return 0;
// }

/*
    How to convert Memoization to Tabulation ?
    1. Declare base case
    2. Express all states in for loop
    3. Copy the recurrence and write
*/