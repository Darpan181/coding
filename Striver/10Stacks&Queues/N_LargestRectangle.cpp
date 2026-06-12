// brute force : ans = arr[i] * ( nse - pse - 1 )
#include<bits/stdc++.h>
using namespace std;
int largestRectangle(vector<int> &arr){
    stack<int> st;
    int maxArea = 0;
    int nse , pse, element;
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            maxArea = max(arr[element] * (nse - pse - 1), maxArea);
        }
        st.push(i); // push index not element
    }
    while(!st.empty()){
        nse = arr.size();
        element = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();
        maxArea = max(arr[element] * (nse - pse - 1), maxArea);
    }
    return maxArea;
}
int main(){
    vector<int> histogram = {2,1,5,6,2,3};
    cout<<largestRectangle(histogram);
return 0;
}