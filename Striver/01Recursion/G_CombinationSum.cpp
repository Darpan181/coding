#include<iostream>
#include<vector>
using namespace std;

void CombinationSum(int idx, int target, vector<int>&arr, vector<int>ds, vector<vector<int>>&res){
    if(idx==arr.size()){
        if(target==0){
            res.push_back(ds);
        }
        return;
    }
    if(arr[idx] <= target){
        ds.push_back(arr[idx]);
        CombinationSum(idx,target-arr[idx],arr,ds,res);
        ds.pop_back();
    }
    CombinationSum(idx+1,target,arr,ds,res);
}

int main(){
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> res;
    vector<int> ds;
    CombinationSum(0,7,arr,ds,res);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;  
    }
return 0;
}