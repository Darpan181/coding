#include<bits/stdc++.h>
using namespace std;
int uniquePaths(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int up = uniquePaths(grid, i - 1, j, dp);
    int left = uniquePaths(grid, i, j - 1, dp);

    return dp[i][j] = up + left;
}
int main(){
    vector<vector<int>> grid = {
        {0,0,0}, {0,1,0}, {0,0,0}
    };
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m , vector<int> (n , -1));
    cout<<uniquePaths(grid, m - 1, n - 1, dp);
return 0;
}