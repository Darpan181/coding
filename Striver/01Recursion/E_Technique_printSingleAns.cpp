#include<iostream>
#include<vector>
using namespace std;

bool SumofSubsequence(int arr[], int n, int k, int idx, int sum, vector<int> res){
    if(idx==n){
        //condition satisfied
        if(sum==k){
            for(int i=0; i<res.size(); i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        //condition not satisfied
        return false;
    }
    res.push_back(arr[idx]);
    sum += arr[idx];

    if(SumofSubsequence(arr,n,k,idx+1,sum,res) == true) return true;

    res.pop_back();
    sum -= arr[idx];
    if(SumofSubsequence(arr,n,k,idx+1,sum,res) == true) return true;

    return false; // upr dono m se koi bhi na chle agr
}

int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    int k = 2;
    SumofSubsequence(arr,n,2,0,0,v);
return 0;
}