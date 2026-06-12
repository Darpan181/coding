#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int numbEnclaves(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis (n, vector<int> (m, 0));
    queue<pair<int, int>> q;
    for(int j=0; j<m; j++){
        if(grid[0][j] == 1 && vis[0][j] == 0){
            q.push({0, j});
            vis[0][j] = 1;
        }
        if(grid[n-1][j] == 1 && vis[n-1][j] == 0){
            q.push({n-1, j});
            vis[n-1][j] = 1;
        }
    }
    for(int i=0; i<n; i++){
        if(grid[i][0] == 1 && vis[i][0] == 0){
            q.push({i, 0});
            vis[i][0] = 1;
        }
        if(grid[i][m-1] == 1 && vis[i][m-1] == 0){
            q.push({i, m-1});
            vis[i][m-1] = 1;
        }
    }
    while(q.empty() == false){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> grid = {
        {0,0,0,0}, {1,0,1,0}, {0,1,1,0}, {0,0,0,0}
    };
    cout<<numbEnclaves(grid);
return 0;
}