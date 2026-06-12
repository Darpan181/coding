#include<bits/stdc++.h>
using namespace std;
vector<int> findNSE(vector<int> &arr){
    vector<int> nse(arr.size());
    stack<int> st;
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> &arr){
    vector<int> pse(arr.size());
    stack<int> st;
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
long long SumSubArrayMinm(vector<int> &arr){
    int n = arr.size();
    long long total = 0;
    int mod = int(1e9 + 7);
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    for(int i=0; i<n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (1LL * right * left % mod * arr[i] % mod)) % mod;
    }
    return total;
}
int main(){
    vector<int> arr = {3, 1, 2, 4};
    cout<<SumSubArrayMinm(arr);
return 0;
}