#include<bits/stdc++.h>
using namespace std;
/*..............................BRUTE SOLUTION............................
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
        return;
    }
    
    void pop() {
        st.pop();
        return;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
*/

//......................OPTIMAL SOLUTION.........................
// use formula to preserve previous value :  2*val - prev_min = newVal
class MinStack {
public:
    stack<long long> st;
    long long minm;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minm = val;
        }
        else{
            if(val >= minm) st.push(val);
            else{
                st.push(2LL * val - minm);
                minm = val;
            }
        }
        return;
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < minm){
            minm = 2LL * minm - x;
        } 
    }
    
    int top() {
        long long x = st.top();
        if(minm < x) return x;
        return minm;
    }
    
    int getMin() {
        return minm;
    }
};

