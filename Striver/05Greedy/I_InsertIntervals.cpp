// divide the given array into three parts: left, middle, right
// we have to deal with middle one
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> insertInterval(vector<vector<int>>&arr, vector<int>& interval){
    int n = arr.size();
    int i = 0;
    vector<vector<int>> res;
    // LEFT
    while(i < n && arr[i][1] < interval[0]){
        res.push_back(arr[i]);
        i++;
    }
    // MIDDLE
    while(i < n && arr[i][0] <= interval[1]){
        interval[0] = min( interval[0], arr[i][0] );
        interval[1] = max( interval[1], arr[i][1] );
        i++;
    }
    res.push_back(interval);
    // RIGHT
    while(i < n){
        res.push_back(arr[i]);
        i++;
    }
    return res;
}
int main(){
    vector<vector<int>> intervals = {
        {1,2}, {3,4}, {6,7}, {8,10}, {12,16}
    };
    vector<int> newInterval = {5,8};
    vector<vector<int>> ans = insertInterval(intervals, newInterval);
    for (auto &v : ans) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }
    cout << endl;
return 0;
}