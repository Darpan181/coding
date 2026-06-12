// anyone who is a part of cycle -> not our answer
// anyone leads to a cycle -> not our answer
#include<bits/stdc++.h>
using namespace std;
bool dfsCheck(int node, vector<vector<int>>& grid, int vis[], int pathvis[], int check[]){
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] = 0;
    for(auto it : grid[node]){
        if(vis[it] == 0){
            if(dfsCheck(it, grid, vis, pathvis, check) == true){
                check[node] = 0;
                return true;
            }
        }
        else if(pathvis[it] == 1){
            check[it] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathvis[node] = 0;
    return false;
}
vector<int> safeNodes(vector<vector<int>>& grid){
    int v = grid.size();
    int vis[v] = {0};
    int pathvis[v] = {0};
    int check[v] = {0};
    vector<int> safeNodes;
    for(int i=0; i<v; i++){
        if(vis[i] == 0){
            dfsCheck(i, grid, vis, pathvis, check);
        }
    }
    for(int i=0; i<v; i++){
        if(check[i] == 1) safeNodes.push_back(i);
    }
    return safeNodes;
}
int main(){
    vector<vector<int>> grid = {
        {1,2}, {2,3}, {5}, {0}, {5}, {}, {}
    };
    vector<int> ans = safeNodes(grid);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}