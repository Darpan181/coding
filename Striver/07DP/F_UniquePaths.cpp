#include<bits/stdc++.h>
using namespace std;
//............................MEMOIZATION................................
int uniquePaths(int i, int j, vector<vector<int>>& dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int up = uniquePaths(i - 1 , j, dp);
    int left = uniquePaths(i , j - 1, dp);

    return dp[i][j] = up + left;
}

//............................TABULATION...............................
int uniquePathsTab(int m , int n){
    vector<vector<int>> dp(m , vector<int> (n));
    dp[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 && j == 0) continue;
            else{
                int right = 0 , down = 0;
                if(i > 0) right = dp[i - 1][j];
                if(j > 0) down = dp[i][j - 1];

                dp[i][j] = right + down;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main(){
    int m = 3 , n = 7;
    vector<vector<int>> dp(m , vector<int> (n , -1));
    //cout<<uniquePaths(m - 1 , n - 1 , dp);
    cout<<uniquePathsTab(m , n);
return 0;
}