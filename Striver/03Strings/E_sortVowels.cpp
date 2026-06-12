#include<bits/stdc++.h>
using namespace std;
void sortVowels(string &s){
    int n = s.size();
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for(int i=0; i<n; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            lower[s[i] - 'a']++;
            s[i] = '#';
        }
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }
    string ans = "";
    for(int i=0; i<26; i++){
        while(upper[i] > 0){
            ans += i + 'A'; 
            upper[i]--;
        }
    }
    for(int i=0; i<26; i++){
        while(lower[i] > 0){
            ans += i + 'a'; 
            lower[i]--;
        }
    }
    int j = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '#'){
            s[i] = ans[j++];
        }
    }
    return;
}
int main(){
    string s = "lEetcOde";
    sortVowels(s);
    cout<<s;
return 0;
}