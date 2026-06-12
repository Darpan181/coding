// max length subarray with atmost 2 types of numbers
#include<bits/stdc++.h>
using namespace std;
/* ...................BRUTE SOLUTION........................
int maxFruits(vector<int> &arr){
    int maxlen = 0;
    for(int i=0; i<arr.size(); i++){
        set<int> st;
        for(int j=i; j<arr.size(); j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                maxlen = max(maxlen, j - i + 1);
            }
            else break;
        }
    }
    return maxlen; // TC : O(N ^ 2)
}
*/
int maxFruits(vector<int> &arr, int k){
    int l = 0 , r = 0 , maxlen = 0;
    map<int, int> mpp; // {num, frequency}
    int n = arr.size();
    while(r < n){
        mpp[arr[r]]++;
        if(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) 
                mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size() <= k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}
int main(){
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<maxFruits(arr, 2); // 2 is number of basket
return 0;
}