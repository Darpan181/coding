#include<bits/stdc++.h>
using namespace std;
long long findTime(vector<int> &arr , int speed){
        long long time = 0;
        for(int i=0; i<arr.size(); i++){
            time += (arr[i] + speed - 1) / (long long)speed;
        }
        return time;
}
int minEatingSpeed(vector<int> &arr , int h){
    int n = arr.size();
    if(n == 0) return 0;
    int low = 1 , high = *max_element(arr.begin(), arr.end());
    int ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(findTime(arr , mid) <= h){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout<<minEatingSpeed(piles, h);
return 0;
}