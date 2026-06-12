#include<bits/stdc++.h>
using namespace std;
bool findElement(vector<vector<int>> &arr, int target){
    int row = 0 , col = arr[0].size() - 1;
    while(row < arr.size() && col >= 0){
        if(arr[row][col] == target) return true;
        else if(arr[row][col] < target) row++;
        else col--;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {
        {1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}
    };
    cout<<findElement(matrix, 14); // TC : O( n + m ) 
return 0;
}