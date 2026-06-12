#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    int i = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > 0) st.push(arr[i]);
        else{
            while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i])){
                st.pop();
            }
            if(!st.empty() && st.top() == abs(arr[i])) st.pop();
            else if(st.empty() || st.top() < 0){ // pushing negative element
                st.push(arr[i]);
            }
        }
    }
    vector<int> remr;
    while(!st.empty()){
        remr.push_back(st.top());
        st.pop();
    }
    reverse(remr.begin(), remr.end());
    return remr;
}
int main(){
    vector<int> asteroid = {4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans = asteroidCollision(asteroid);
    for(auto it : ans){
        cout<<it<<" ";
    }
return 0;
}