#include<bits/stdc++.h>
using namespace std;
int longestSubstringNR(string s){
    int maxlen = 0;
    int i = 0, j = 0;
    vector<int> hash(256, 0);
    while(j < s.size()){
        if(hash[s[j]] == 0){
            hash[s[j]]++;
            maxlen = max( maxlen, j - i + 1 );
            j++;
        }
        else{
            hash[s[i]]--;
            i++;
        }
    }
    return maxlen;
}
int main(){
    string s = "abcdecbeadf";
    int ans = longestSubstringNR(s);
    cout<<ans;
return 0;
}