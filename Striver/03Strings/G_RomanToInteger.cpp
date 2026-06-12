#include<bits/stdc++.h>
using namespace std;
int romanToInteger(string s){
    int n = s.size();
    map<char, int> romans;
        romans['I'] = 1; romans['V'] = 5; romans['X'] = 10; romans['L'] = 50; romans['C'] = 100; romans['D'] = 500; romans['M'] = 1000;
    int ans = 0;
    for(int i=0; i <n-1; i++){
        if(romans[s[i]] < romans[s[i + 1]]){
            ans -= romans[s[i]];
        }
        else{
            ans += romans[s[i]];
        }
    }
    ans += romans[s[n - 1]];
    return ans;
}
int main(){
    string s = "CCCXXXV";
    int ans = romanToInteger(s);
    cout<<ans;
return 0;
}