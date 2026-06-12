#include<bits/stdc++.h>
using namespace std;
int maxList(vector<int> &arr){
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxEle = max(arr[i], maxEle);
    }
    return maxEle;
}
long listSum(vector<int> &arr){
    long long sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}
int FindCapacity(vector<int> &arr , int capacity){
    int nod = 1;
    int x = 0; // current load
    for(int i=0; i<arr.size(); i++){
        if(arr[i] + x <= capacity){
            x += arr[i];
        }
        else{
            nod++;
            x = arr[i];
        }
    }
    return nod;
}
int shipWithinDays(vector<int> &weights, int days){
    int low = maxList(weights) , high = listSum(weights);
    int ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(FindCapacity(weights, mid) <= days){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout<<shipWithinDays(weights, days);
return 0;
}