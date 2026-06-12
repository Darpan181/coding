#include<iostream>
#include<vector>
using namespace std;
class Stack{
public:
    vector<int> v; // no overflow condition
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        if(v.size()==0){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        v.pop_back();
    }
    int top(){
        if(v.size()==0){
            cout<<"Stack is Empty"<<endl;
        }
        return v[v.size()];
    }
    int size(){
        return v.size();
    }
};
int main(){
    Stack st;
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
return 0;
}