#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {2,3,-2,4};
    int n = arr.size();
    int res = INT_MIN;
    int pref = 1 , suff = 1;
    for(int i=0; i<n; i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref = pref * arr[i];
        suff = suff * arr[i];
        res = max(res , max(pref , suff));
    }
    cout<<res;
return 0;
}