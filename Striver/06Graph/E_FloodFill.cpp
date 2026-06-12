#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image, int iniColor, int newColor){//can be done using either dfs or bfs
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {-1, 0, 1, 0};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[j];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, iniColor, newColor);
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    dfs(sr, sc, ans, image, iniColor, newColor);
    return ans;
}
int main(){
    vector<vector<int>> image = {
        {1,1,1}, {2,2,0}, {2,2,2}
    };
    int sr = 2;
    int sc = 0;
    int newColor = 3;
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}