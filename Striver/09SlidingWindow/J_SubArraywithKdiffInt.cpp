/*
convert the question into :  no of subarrays where different integers <= k
== k -> ( <= k ) - ( <= k - 1 )   

Note:- Just a small trick if you asked longest then u need to apply sliding window directly and if you were asked to find n. of subarrays with exactly  k elements then u need to firstly find at most k - at most k-1;
*/
#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &arr, int k){
    int l = 0 , r = 0 , n = arr.size();
    map<int, int> mpp; // {num , freq}
    int count = 0;
    while(r < n){
        mpp[arr[r]]++;
        while(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        count = count + (r - l + 1);
        r++;
    }
    return count;
}
int subArrayWithKdistinct(vector<int> &arr, int k){
    return func(arr, k) - func(arr, k - 1);
}
int main(){
    vector<int> arr = {1, 2, 1, 2, 3};
    cout<<subArrayWithKdistinct(arr, 2);
return 0;
}