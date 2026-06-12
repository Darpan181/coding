#include<bits/stdc++.h>
using namespace std;
string minWindowSubString(string s, string t){
    int n = s.size() , m = t.size();
    vector<int> hash(256, 0);
    for(int i=0; i<m; i++){
        hash[t[i]]++;
    }
    int sIndex = -1 , count = 0 , minlen = INT_MAX;
    int l = 0 , r = 0;
    while(r < n){
        if(hash[s[r]] > 0){
            count++;
        }
        hash[s[r]]--;
        while(count == m){
            if(r - l + 1 < minlen){
                minlen = r - l + 1;
                sIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]] > 0){
                count--;
            }
            l++;
        }
        r++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minlen);
}
int main(){
    string s = "ddaaabbca";
    string t = "abc";
    cout<<minWindowSubString(s, t);
return 0;
}