#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& arr, int idx, vector<int>& dp){
    if(idx == 0) return max(0, arr[idx]);
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    int pick = arr[idx] + find(arr, idx - 2, dp);
    int notPick = 0 + find(arr, idx - 1, dp);

    return dp[idx] = max(pick, notPick);
}
int rob(vector<int>& arr, int n){
    if(n == 1) return arr[0];
    vector<int> temp1 , temp2;
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(arr[i]);
        if(i != n-1) temp2.push_back(arr[i]);
    }
    vector<int> dp1(temp1.size() , -1);
    vector<int> dp2(temp2.size() , -1);

    return max(find(temp1, temp1.size()-1, dp1) , find(temp2, temp2.size()-2, dp2));
}
int main(){
    vector<int> arr = {2, 3, 2};
    int n = arr.size();
    cout<<rob(arr, n - 1);
return 0;
}