#include<bits/stdc++.h>
using namespace std;
void solve(int idx, int n, vector<int> &vis, vector<int> &ds, vector<vector<int>> &ans){
    if(ds.size() == n){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<n; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            ds.push_back(i + 1);
            solve(idx + 1, n, vis, ds, ans);
            ds.pop_back();
            vis[i] = 0;
        }
    }
}
int main(){
    int n = 3;
    vector<int> vis (n , 0);
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, n, vis, ds, ans);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}