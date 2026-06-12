#include<bits/stdc++.h>
using namespace std;
void reverse(string &s){
    int i = 0 , j = s.size() - 1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return;
}
string removeKdigits(string s, int k){
    stack<char> st;
    int n = s.size();
    for(int i=0; i<n; i++){
        while(!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')){
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while(k > 0){
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    while(res.size() != 0 && res.back() == '0'){
        res.pop_back();
    }
    reverse(res);
    if(res.empty()) return "0";
    return res;
}
int main(){
    string s = "1432219";
    cout<<removeKdigits(s, 3);
return 0;
}