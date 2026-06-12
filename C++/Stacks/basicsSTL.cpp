#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    cout<<st.size()<<endl;
    st.push(30);
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
return 0;
}