#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "abaccb";
    int n = s.size();
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for(int i=0; i<n; i++){
        if(s[i] >= 'a'){
            lower[s[i] - 'a']++;
        }
        else{
            upper[s[i] - 'A']++;
        }
    }
    int count = 0;
    int odd = 0;
    for(int i=0; i<26; i++){
        if(lower[i] % 2 == 0){
            count += lower[i];
        }
        else{
            count = count + lower[i] - 1;
            odd = 1;
        }
        if(upper[i] % 2 == 0){
            count += upper[i];
        }
        else{
            count = count + upper[i] - 1;
            odd = 1;
        }
    }
    cout<<count + odd;
return 0;
}