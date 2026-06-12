#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SubsetND(int idx, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=idx; i<nums.size(); i++){
    //if it is not the first && if it is duplicate
        if(i!=idx && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        SubsetND(i+1,nums,ds,ans);
        ds.pop_back();
    }
}

int main(){
    vector<int> nums = {1,2,1};
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(),nums.end()); //1st step is to sort the given array
    SubsetND(0,nums,ds,ans);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}