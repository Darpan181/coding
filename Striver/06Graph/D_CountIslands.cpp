#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    while(q.empty() == false){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        //traverse the neighbour
        for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int countIslands(vector<vector<int>> grid){
    int n = grid.size();// row
    int m = grid[0].size();// coloumn
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int count = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(vis[row][col] == 0 && grid[row][col] == 1){
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> grid = {
        {0,1,1,0}, {0,1,1,0}, {0,0,1,0}, {0,0,0,0}, {1,1,0,1}
    };
    cout<<countIslands(grid);
return 0;
}
