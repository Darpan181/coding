#include<bits/stdc++.h>
using namespace std;
int longestSubstringNRC(string &s){
    int n = s.size();
    int l = 0 , r = 0 , maxlen = 0, len;
    vector<int> hash(256, -1);
    while(r < n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);
        hash[s[r]] = r;
        r++;
    }
    return maxlen;
}
int main(){
    string s = "cadbzabcs";
    cout<<longestSubstringNRC(s);
return 0;
}