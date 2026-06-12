#include<iostream>
#include<vector>
using namespace std;

void permutation(vector<int>&nums, vector<int>&ds, int map[]){
    if(ds.size()==nums.size()){
        for(int i=0; i<ds.size(); i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<nums.size(); i++){
        if(!map[i]){
            ds.push_back(nums[i]);
            map[i] = 1;
            permutation(nums,ds,map);
            map[i] = 0;     //upr jate time (recursion tree)
            ds.pop_back();  // vapis unmap krdo or ds se htado
        }
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> ds;
    int map[nums.size()] = {0}; //all elements zero
    permutation(nums,ds,map);
return 0;
}