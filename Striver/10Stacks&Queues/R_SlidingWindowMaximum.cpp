#include<bits/stdc++.h>
using namespace std;
vector<int> MaxSlidingWindow(vector<int> &arr, int k){
    vector<int> ans;
    deque<int> dq;
    for(int i=0; i<arr.size(); i++){
        if(!dq.empty() && dq.front() <= i - k){ // maintaining window size
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){ // maintaining decreasing order
            dq.pop_back();
        }
        dq.push_back(i); // push index
        if(i >= k - 1) ans.push_back(arr[dq.front()]); // store answer once first window is formed
    }
    return ans;
}
int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = MaxSlidingWindow(arr, 3);
    for(int it : ans){
        cout<<it<<" ";
    }
return 0;
}