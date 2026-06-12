#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.top()<<endl;
    stack<int> gt;
    stack<int> rt;
    //empty stack from st to gt
    for(int i=1; i<=st.size(); i++){
        gt.push(st.top());
        st.pop();
    }
    //empty stack from gt to rt
    while(gt.size()>0){
        rt.push(gt.top());
        gt.pop();
    }
    //empty stack from rt to st again
    while(rt.size()>0){
        st.push(rt.top());
        rt.pop();
    }
    cout<<st.top()<<endl;
return 0;
}