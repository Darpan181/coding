#include<bits/stdc++.h>
using namespace std;
/*.....................BRUTE SOLUTION.....................
int longestSubString_DistinctK(string &s, int k){
    int n = s.size();
    int maxlen = 0;
    map<char, int> mpp;
    for(int i=0; i<n; i++){
        mpp.clear();
        for(int j=i; j<n; j++){
            mpp[s[j]]++;
            if(mpp.size() <= k){
                maxlen = max(maxlen, j - i + 1);
            }
            else break;
        }
    } 
    return maxlen;
}
*/

//.......................OPTIMAL SOLUTION.........................
int longestSubString_DistinctK(string &s, int k){
    int l = 0 , r = 0 , maxlen = 0;
    map<char, int> mpp;
    while(r < s.size()){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }
        if(mpp.size() <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    string s = "aaabbccd";
    cout<<longestSubString_DistinctK(s, 2);
return 0;
}