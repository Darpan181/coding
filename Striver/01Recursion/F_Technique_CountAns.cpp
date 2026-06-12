#include<iostream>
#include<vector>
using namespace std;

int SumofSubsequence(int arr[], int n, int idx, int k, vector<int> res, int sum){
    if(idx==n){
        if(sum==k) return 1; //note it
        else return 0;
    }
    res.push_back(arr[idx]);
    sum += arr[idx];

    int left = SumofSubsequence(arr,n,idx+1,k,res,sum);//TAKE
    
    res.pop_back();
    sum -= arr[idx];

    int right = SumofSubsequence(arr,n,idx+1,k,res,sum);//NOT TAKE

    return left + right; //Technique
}

int main(){
    int arr[] = {2,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    int k = 7;
    cout<<SumofSubsequence(arr,n,0,k,v,0);
return 0;
}