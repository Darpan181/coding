#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    string s = "aaabbcddaabffg";
    stack<char> st;
    st.push(s[0]);
    int i = 1;
    while(i != s.length()){
        if(st.top()==s[i]) i++;
        else{
            st.push(s[i]);
            i++;
        }
    }
    stack<char> helper;
    while(st.size()>0){
        helper.push(st.top());
        st.pop();
    }
    while(helper.size()>0){
        cout<<helper.top();
        helper.pop();
    }
return 0;
}