#include<bits/stdc++.h>
using namespace std;
vector<int> lpsFind(vector<int> &lps, string needle){
    int pre = 0 , suff = 1;
    int n = needle.size();
    while(suff < n){
        // match
        if(needle[pre] == needle[suff]){
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        // not match
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
    return lps;
}
bool KMPmatch(string haystack, string needle){
    vector<int> lps(needle.size(), 0);
    lps = lpsFind(lps, needle);
    int first = 0 , second = 0;
    while(second < needle.size() && first < haystack.size()){
        if(needle[second] == haystack[first]){
            first++;
            second++;
        }
        else{
            if(second == 0) first++;
            else second = lps[second - 1];
        }
    }
    if(second == needle.size()) return true;
    else return false;
}
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int repeat = 1;
        string temp = a;
        while(temp.size() < b.size()){
            temp += a;
            repeat++;
        }
        // KMP pattern search
        if(KMPmatch(temp , b)) return repeat;
        
        // temp + a , KMP search
        if(KMPmatch(temp + a , b)) return repeat + 1;

        return -1;
    }
int main(){
    string a = "abcd";
    string b = "cdabcdab";
    cout<<repeatedStringMatch(a, b);
return 0;
}