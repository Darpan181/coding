#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;    
}
int main(){
    vector<int> arr = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> ans = nextGreaterElement(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
return 0;
}