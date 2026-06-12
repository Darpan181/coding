// 0 1 1 2 3 5 8 13 21
#include<bits/stdc++.h>
using namespace std;
// int fibo(int n , vector<int>& dp){
//     if(n <= 1) return n;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] = fibo(n - 1 , dp) + fibo(n - 2 , dp);
// }
int fibo(int n){
    int prev2 = 0 , prev = 1;
    int curr;
    for(int i=2; i<=n; i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }        
    return curr;
}
int main(){
    int n = 8;
    vector<int> dp(n + 1 , -1);
    cout<<fibo(n);
return 0;
}