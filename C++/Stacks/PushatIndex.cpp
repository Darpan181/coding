#include<iostream>
#include<stack>
using namespace std;
stack<int> PushatIndex(stack<int>& st, int idx, int val){
    stack<int> temp;
    for(int i=st.size(); i>=idx; i--){//while(st.size()>idx)
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
         st.push(temp.top());
         temp.pop();
    }
    return st;
}
void display(stack<int>& st){
    stack<int> gt;
    while(st.size()>0){
        gt.push(st.top());
        st.pop();
    }
    while(gt.size()>0){
        cout<<gt.top()<<" ";
        st.push(gt.top());
        gt.pop();
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);
    cout<<endl;
    stack<int> a = PushatIndex(st,3,70);
    display(a);
return 0;
}