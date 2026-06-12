#include<bits/stdc++.h>
using namespace std;
string PostfixToInfix(string s){
    int i = 0 , n = s.size();
    stack<string> st;
    while(i < n){
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ){
            st.push(string(1,s[i])); // converts char into string
        }
        else{
            string t1 = st.top() ; st.pop();
            string t2 = st.top() ; st.pop();
            string cal = "(" + t2 + s[i] + t1 + ")";
            st.push(cal);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s = "AB-DE+F*/";
    cout<<PostfixToInfix(s);
return 0;
}