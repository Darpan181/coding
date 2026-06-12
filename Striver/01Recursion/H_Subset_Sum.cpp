#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSum(int arr[], int n, int idx, int sum, vector<int>&res){
    if(idx==n){
        res.push_back(sum);
        return;
    }
    subsetSum(arr,n,idx+1,sum+arr[idx],res);
    subsetSum(arr,n,idx+1,sum,res);
}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    subsetSum(arr,n,0,0,v);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
return 0; 
}