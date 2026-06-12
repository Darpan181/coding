#include<bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k){
    int l = 0 , r = 0 , n = s.size();
    int maxlen = 0 , mfreq = 0;
    vector<int> hash(26, 0);
    while(r < n){
        hash[s[r] - 'A']++;
        mfreq = max(mfreq, hash[s[r] - 'A']);
        while((r - l + 1) - mfreq > k){
            hash[s[l] - 'A']--;
            mfreq = 0;
            for(int i=0; i<26; i++) mfreq = max(mfreq, hash[i]);
            l++;
        }
        if((r - l + 1) - mfreq <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    string s = "AAABBCCD";
    cout<<characterReplacement(s, 2);
return 0;
}