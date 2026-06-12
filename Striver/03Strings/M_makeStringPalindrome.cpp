#include<bits/stdc++.h>
using namespace std;
string reverseStr(string s){
    int i = 0 , j = s.size() - 1;
    while(i < j){
        swap(s[i] , s[j]);
        i++;
        j--;
    }
    return s;
}
int FindLPS(string s){
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
int makePalindrome(string s){
    int n = s.size();
    string rev =  reverseStr(s);
    s += "#";
    s += rev;
    int len = FindLPS(s);
    return n - len;
}
int main(){
    string s = "ROORSP";
    int ans = makePalindrome(s);
    cout<<ans;
return 0;
}