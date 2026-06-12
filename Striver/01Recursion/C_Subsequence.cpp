#include<iostream>
#include<vector>
using namespace std;

void subsequence(int idx, int arr[], int n, vector<int> res){
    if(idx==n){
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" "; 
        }
        cout<<endl;
        return;
    }
    res.push_back(arr[idx]);
    subsequence(idx+1,arr,n,res); //TAKE
    res.pop_back();
    subsequence(idx+1,arr,n,res); //NOT TAKE
}

int main(){
    vector<int> v;
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    subsequence(0,arr,n,v);
return 0;
}

