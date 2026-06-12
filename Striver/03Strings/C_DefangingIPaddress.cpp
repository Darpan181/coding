#include<bits/stdc++.h>
using namespace std;
string defangIP(string s){
    int n = s.size();
    string temp = "";
    for(int i=0; i<n; i++){
        if(s[i] == '.'){
            temp += "[.]";
        }
        else temp += s[i];
    }
    return temp;
}
int main(){
    string s = "255.100.25.60";
    string ans = defangIP(s);
    cout<<ans;
return 0;
}