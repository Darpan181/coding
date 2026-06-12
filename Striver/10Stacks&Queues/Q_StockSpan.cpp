#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = -1;
    StockSpanner() {
        idx = -1;
        // clear stack
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        idx = idx + 1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = idx - (st.empty() ? -1 : st.top().second);
        st.push({price, idx});
        return ans;
    }
};