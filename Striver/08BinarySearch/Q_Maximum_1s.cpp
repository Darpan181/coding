#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &arr , int x){
    int ans = arr.size();
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1; 
    }
    return ans;
}
int maximum1s(vector<vector<int>> &arr){
    int n = arr.size() , m = arr[0].size();
    int cnt_max = 0;
    int index = -1;
    for(int i=0; i<n; i++){
        int cnt_ones = m - lower_bound(arr[i], 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}
    };
    cout<<maximum1s(matrix);
return 0;
}