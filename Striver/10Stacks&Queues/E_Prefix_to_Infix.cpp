#include<bits/stdc++.h>
using namespace std;
string reverse(string s){
    int i = 0 , j = s.size() - 1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
string PrefixToInfix(string s){
    s = reverse(s);
    int i = 0 , n = s.size();
    stack<string> st;
    while(i < n){
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top() ; st.pop();
            string t2 = st.top() ; st.pop();
            string cal = "(" + t1 + s[i] + t2 + ")";
            st.push(cal);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s = "*+PQ-MN";
    cout<<PrefixToInfix(s);
return 0;
}