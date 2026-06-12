#include<iostream>
#include<vector>
using namespace std;

void SumofSubsequence(int arr[], int n, int idx, int k, vector<int> res, int sum){
    if(idx==n){
        if(sum==k){
            for(int i=0; i<res.size(); i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    res.push_back(arr[idx]);
    sum += arr[idx];
    SumofSubsequence(arr,n,idx+1,k,res,sum);//TAKE
    res.pop_back();
    sum -= arr[idx];
    SumofSubsequence(arr,n,idx+1,k,res,sum);//NOT TAKE
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    int k = 2;
    SumofSubsequence(arr,n,0,k,v,0);
return 0;
}