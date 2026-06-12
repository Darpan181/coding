#include<bits/stdc++.h>
using namespace std;
int sqRoot(int n){
    int low = 1 , high = n - 1;
    int ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int main(){
    int n = 28;
    cout<<sqRoot(n);
return 0;
}