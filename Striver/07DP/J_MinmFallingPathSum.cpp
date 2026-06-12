#include<bits/stdc++.h>
using namespace std;
//...................................MEMOIZATION.......................................
int minPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    if(j < 0 || j >= grid[0].size()) return 1e9;
    if(i == 0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + minPathSum(grid, i - 1, j, dp);
    int diagL = grid[i][j] + minPathSum(grid, i - 1, j - 1, dp);
    int diagR = grid[i][j] + minPathSum(grid, i - 1, j + 1, dp);

    return dp[i][j] = min(up , min(diagL , diagR));
}

//...................................TABULATION......................................
int minPathSumTab(vector<vector<int>>& grid){
    int n = grid.size() , m = grid[0].size();
    vector<vector<int>> dp(n , vector<int> (m , 0));
    for(int i=0; i<m; i++){
        dp[0][i] = grid[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int up = grid[i][j] + dp[i - 1][j];

            int diagL = grid[i][j];
            if(j > 0) diagL += dp[i - 1][j - 1];
            else diagL += 1e9;

            int diagR = grid[i][j];
            if(j < m - 1) diagR += dp[i - 1][j + 1];
            else diagR += 1e9;

            dp[i][j] = min(up , min(diagL , diagR));
        }
    }
    int minm = INT_MAX;
    for(int i=0; i<m; i++){
        minm = min(minm , dp[n - 1][i]);
    }
    return minm;
}
int main(){
    vector<vector<int>> grid = {
        {1,3,1}, {1,5,1}, {4,2,1}
    };
    int n = grid.size();
    int m = grid[0].size();
    // int minm = INT_MAX;
    // vector<vector<int>> dp(n , vector<int> (m , -1));
    // for(int i=0; i<m; i++){
    //     minm = min(minm , minPathSum(grid, n - 1, i, dp));
    // }
    // cout<<minm;
    cout<<minPathSumTab(grid);
return 0;
}