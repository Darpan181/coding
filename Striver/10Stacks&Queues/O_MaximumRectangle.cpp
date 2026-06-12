#include<bits/stdc++.h>
using namespace std;
int largestHist(vector<int> &arr){
    stack<int> st;
    int maxArea = 0;
    int nse , pse, element;
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            long long area = 1LL * arr[element] * (nse - pse - 1);
            maxArea = max(maxArea, (int)area);
        }
        st.push(i); // push index not element
    }
    while(!st.empty()){
        nse = arr.size();
        element = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();
        long long area = 1LL * arr[element] * (nse - pse - 1);
        maxArea = max(maxArea, (int)area);
    }
    return maxArea;
}
int maximumRectangle(vector<vector<int>> &arr){
    if(arr.size() == 0) return 0;
    int n = arr.size() , m = arr[0].size();
    int maxArea = 0;
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));
    for(int j=0; j<m; j++){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i][j];
            if(arr[i][j] == 0) sum = 0;
            prefixSum[i][j] = sum;
        }
    }
    for(int i=0; i<n; i++){
        maxArea = max(maxArea , largestHist(prefixSum[i]));
    }
    return maxArea;
}
int main(){
    vector<vector<int>> matrix = {
        {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,1,0}
    };
    cout<<maximumRectangle(matrix);
return 0;
}