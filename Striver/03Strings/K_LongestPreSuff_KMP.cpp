#include<bits/stdc++.h>
using namespace std;
int longestPreSuff(string s){
    int n = s.size();
    vector<int> lps(n , 0);
    int pre = 0 , suff = 1;
    while(suff < n){
        if(s[pre] == s[suff]){
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        else{
            if(pre == 0){
                lps[suff] = 0;
                suff++;
            }
            else{
                pre = lps[pre - 1];        
            }
        }
    }
    return lps[n - 1];
}
int main(){
    string s = "ABCABDABCABDABDAB";
    int ans = longestPreSuff(s);
    cout<<ans;
return 0;
}