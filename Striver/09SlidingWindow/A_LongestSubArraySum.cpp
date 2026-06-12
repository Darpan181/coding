// longest subarray sum <= k
#include<bits/stdc++.h>
/*
vector<int> arr = {2, 5, 1, 7, 10};
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
        cout<<endl;
        }
    }
*/

// sliding window approach
using namespace std;
int longestSubArraySum(vector<int> &arr, int k){
    int n = arr.size();
    int l = 0 , r = 0 , sum = 0 , maxlen = 0;
    while(l < n){
        sum = sum + arr[r];
        while(sum > k){
            sum = sum - arr[l];
            l++;
        }
        if(sum <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    vector<int> arr = {2, 5, 1, 7, 10};
    cout<<longestSubArraySum(arr, 14);
return 0;
}