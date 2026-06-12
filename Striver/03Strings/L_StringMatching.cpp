#include<bits/stdc++.h>
using namespace std;
//.........................BRUTE FORCE....................
// int stringMatch(string s1 , string s2){
//     int n1 = s1.size();
//     int n2 = s2.size();
//     for(int i=0; i<=n1-n2; i++){
//         int first = i , second = 0;
//         while(second < n2){
//             if(s1[first] == s2[second]){
//                 first++;
//                 second++;
//             }
//             else break;
//         }
//         if(second == n2) return i;
//     }
//     return -1; // TC : O( n1 * n2 )
// }
//.....................OPTIMAL.............................
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
int stringMatch(string haystack, string needle){
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
    if(second == needle.size()) return first - second;
    else return -1;
}
int main(){
    string s1 = "abcdaabceaabceaabdop";
    string s2 = "aabceaabdo";
    int ans = stringMatch(s1, s2);
    cout<<ans;
return 0;
}