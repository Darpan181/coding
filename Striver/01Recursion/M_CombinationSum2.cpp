#include<bits/stdc++.h>
using namespace std;
void findComb(int idx, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i=idx; i<arr.size(); i++){
        if(i > idx && arr[i] == arr[i - 1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        findComb(i + 1, arr, target - arr[i], ds, ans);
        ds.pop_back();
    }
}
int main(){
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;

    sort(arr.begin() , arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    findComb(0, arr, target, ds, ans);
    for(auto it : ans){
        for(int i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}