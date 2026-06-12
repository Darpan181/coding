// convert the question to : longest subarray with atmost k zero`s
#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOne(vector<int> &arr, int k){
    int n = arr.size();
    int l = 0 , r = 0, maxlen = 0, zeros = 0, len;
    while(r < n){
        if(arr[r] == 0) zeros++;
        while(zeros > k){
            if(arr[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
            len = r - l + 1;
            maxlen = max(maxlen, len);
        }
        r++;
    }
    return maxlen;
}
int main(){
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout<<maxConsecutiveOne(arr, 2);
return 0;
}