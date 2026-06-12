#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> mat = {
        {1,2,3,4}, {5,6,7,8},
        {9,10,11,12}, {13,14,15,16}
    };
    vector<int> ans;
    int row = mat.size();
    int col = mat[0].size();

    int left = 0, right = row - 1;
    int top = 0, bottom = col - 1;
    while(top <= bottom && left <= right){
        //right
        for(int i=left; i<=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        //bottom
        for(int i=top; i<=bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        //left
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        //top
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
return 0;
}