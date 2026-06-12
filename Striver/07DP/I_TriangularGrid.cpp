#include<bits/stdc++.h>
using namespace std;
//.....................................MEMOIZATION......................................
int minimumTotal(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
    if(i == triangle.size() - 1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + minimumTotal(triangle, i + 1, j, dp);
    int diag = triangle[i][j] + minimumTotal(triangle, i + 1, j + 1, dp);

    return dp[i][j] = min(down , diag);
}

//....................................TABULATION.........................................
int minimumTotalTab(vector<vector<int>>& triangle){
    int m = triangle.size();
    vector<vector<int>> dp;
    for(int i=0; i<m; i++){
        dp.push_back(vector<int> (triangle[i].size() , -1));
    }
    for(int i=0; i<m; i++){
        dp[m - 1][i] = triangle[m - 1][i];
    }
    for(int i=m-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down , diag);
        }
    }
    return dp[0][0];
}
int main(){
    vector<vector<int>> triangle = {
        {2}, {3,4}, {6,5,7}, {4,1,8,3}
    };
    int m = triangle.size();
    vector<vector<int>> dp;
    for(int i=0; i<m; i++){
        dp.push_back(vector<int> (triangle[i].size(), -1));
    }
    //cout<<minimumTotal(triangle, 0, 0, dp);
    cout<<minimumTotalTab(triangle);
return 0;
}