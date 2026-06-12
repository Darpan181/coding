#include<bits/stdc++.h>
using namespace std;
long long power(int base , int exp){
    long long result = 1;
    for(int i=1; i<=exp; i++){
        result = result * base;
    }
    return result;
}
int NthRoot(int num, int n){
    int low = 1 , high = num;
    int ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(power(mid, n) <= num){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int main(){
    int n = 68;
    cout<<NthRoot(68, 4);
return 0;
}