#include<bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int> &arr, int dist, int cows){
    int nCows = 1 , last = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] - last >= dist){
            nCows++;
            last = arr[i];
        }
        if(nCows >= cows) return true;
    }
    return false;
}
int minDistance(vector<int> &arr, int cows){
    int n = arr.size();
    sort(arr.begin() , arr.end());
    int low = 1 , high = arr[n - 1] - arr[0];
    int ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canWePlace(arr, mid, cows)){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int main(){
    vector<int> arr = {0, 3, 4, 7, 9, 10};
    int cows = 4;
    cout<<minDistance(arr, cows);
return 0;
}