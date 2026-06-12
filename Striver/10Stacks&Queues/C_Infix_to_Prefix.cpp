#include<bits/stdc++.h>
using namespace std;
int priority(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}
string reverse(string s){
    int i = 0 , j = s.size() - 1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    return s;
}
string InfixToPrefix(string s){
    int n = s.size();
    s = reverse(s);
    int i = 0; stack<char> st; string ans = "";
    while(i < n){
        // operand
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ){
            ans += s[i];
        }
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans = ans + st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){ // not equal to
                    ans = ans + st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return reverse(ans);
}
int main(){
    string s = "a+(b-c)*d";
    cout<<InfixToPrefix(s);
return 0;
}