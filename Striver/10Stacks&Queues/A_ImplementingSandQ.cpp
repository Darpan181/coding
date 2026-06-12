#include<bits/stdc++.h>
using namespace std;
// implementing stack using queue
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=1; i<=s; i++){
            q.push(q.front());
            q.pop();
        }
        return;
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// implementing queue using stack
/*
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()>0){
            int x = st.top();
            helper.push(x);
            st.pop();
        }
        int a = helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
    return a;
    }
    
    int peek() {
        while(st.size()>0){
            int x = st.top();
            helper.push(x);
            st.pop();
        }
        int a = helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
    return a;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
