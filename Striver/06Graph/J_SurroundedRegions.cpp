#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    //grid[row][col] = 'X';
    vis[row][col] = 1;
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 'O'){
            dfs(nrow, ncol, vis, grid);
        }
    }
}
vector<vector<char>> solve(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis (n, vector<int> (m, 0));
    // traverse the first and last row
    for(int j=0; j<m; j++){
        // first row
        if(grid[0][j] == 'O' && vis[0][j] == 0){
            dfs(0, j, vis, grid);
        }
        //last row
        if(grid[n-1][j] == 'O' && vis[n-1][j] == 0){
            dfs(n-1, j, vis, grid);
        }
    }
    // traverse the first and last coloumn
    for(int i=0; i<n; i++){
        // first coloumn
        if(grid[i][0] == 'O' && vis[i][0] == 0){
            dfs(i, 0, vis, grid);
        }
        // last coloumn
        if(grid[i][m-1] == 'O' && vis[i][m-1] == 0){
            dfs(i, m-1, vis, grid);
        }
    }
    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
            if(grid[i][j] == 'O' && vis[i][j] == 0) grid[i][j] = 'X';
        }
    }
    return grid;
}
int main(){
    vector<vector<char>> grid = {
        {'O','O','O'},{'O','O','O'},{'O','O','O'}
    };
    vector<vector<char>> result = solve(grid);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}