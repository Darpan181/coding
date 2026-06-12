#include<bits/stdc++.h>
using namespace std;
void sortString(string &s){
    int n = s.size();
    vector<int> lower(26, 0);
    for(int i=0; i<n; i++){
        lower[s[i] - 'a']++;
    }
    s.clear();
    for(int i=0; i<26; i++){
            while(lower[i] > 0){
                s = s + char('a' + i);
                lower[i]--;
            }
    }
    return;
}
int main(){
    string s = "eabcabd";
    sortString(s);
    cout<<s;
return 0;
}