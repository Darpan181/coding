#include<bits/stdc++.h>
using namespace std;
int maximumPoint(vector<int> &arr, int k){
    int n = arr.size();
    if(k > n) return -1;
    int lsum = 0 , rsum = 0 , maxSum;
    for(int i=0; i<k; i++) lsum += arr[i];
    maxSum = lsum;
    int rIndex = n - 1;
    for(int i=k-1; i>=0; i--){
        lsum -= arr[i];
        rsum += arr[rIndex];
        rIndex--;

        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}
int main(){
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout<<maximumPoint(arr, 4);
return 0;
}