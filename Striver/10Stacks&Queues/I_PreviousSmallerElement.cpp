#include<bits/stdc++.h>
using namespace std;
vector<int> PreviousSmallerElement(vector<int> &arr){
    int n = arr.size();
    stack<int> st ; vector<int> pse(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(arr[i]);
    }
    return pse;
}
int main(){
    vector<int> arr = {5, 7, 9, 6, 7, 4, 5, 1, 3, 7};
    vector<int> ans = PreviousSmallerElement(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
return 0;
}