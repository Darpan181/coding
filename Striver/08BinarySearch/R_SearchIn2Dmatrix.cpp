#include<bits/stdc++.h>
using namespace std;
/*
int binarySearch(vector<int> &arr, int target){
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int findElement(vector<vector<int>> &arr, int target){
    int n = arr.size() , m = arr[0].size();
    for(int i=0; i<n; i++){
        if(arr[i][0] <= target && target <= arr[i][m - 1])
            return binarySearch(arr[i], target);
    }
    return -1;
}
*/

//.....................................OPTIMAL SOLUTION............................
int findElement(vector<vector<int>> &arr, int target){
    int n = arr.size() , m = arr[0].size();
    int low = 0 , high = n * m - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if(arr[row][col] == target) return true;
        else if(arr[row][col] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int main(){
    vector<vector<int>> matrix = {
        {3, 4, 7, 9}, {12, 13, 16, 18}, {20, 21, 23, 29}
    };
    cout<<findElement(matrix, 29);
return 0;
}