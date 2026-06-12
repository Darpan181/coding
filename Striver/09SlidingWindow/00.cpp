#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 1, 3, 4};
    int k = 3;
    int n = arr.size() , count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            set<int> st;
            for(int k=i; k<=j; k++){
                st.insert(arr[k]);
            }
            if(st.size() == k) count++;
        }
    }
    cout<<count;
return 0;
}