#include<bits/stdc++.h>
using namespace std;
int maxList(vector<int> &arr){
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxEle = max(arr[i], maxEle);
    }
    return maxEle;
}
bool possibleBqt(vector<int> &arr, int bqt, int nof, int day){
     int nob = 0 , flw = 0;
     for(int i=0; i<arr.size(); i++){
        if(arr[i] <= day){
            flw++;
            if(flw == nof){
                nob++;
                flw = 0;
            }
        }
        else flw = 0;
     }
     if(nob >= bqt) return true;
     else return false;
}
int minDays(vector<int> &arr, int bqt, int nof){
    if ((long long)bqt * nof > arr.size()) return -1;
    int ans;
    int low = 1 , high = maxList(arr);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(possibleBqt(arr, bqt, nof, mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> blooms = {1,10,3,10,2};
    int m = 3 , k = 1;
    cout<<minDays(blooms, m, k);
return 0;
}