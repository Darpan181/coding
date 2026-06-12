#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], stack<int>& st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 0){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(vector<int> adj[], int v){ // only valid in DAG
    int vis[v] = {0};
    stack<int> st;
    for(int i=0; i<v; i++){
        if(vis[i] == 0){
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int v = 6;
    vector<int> adj[v];
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    vector<int> topo = topoSort(adj, v);
    for(int it : topo){
        cout<<it<<" ";
    }
return 0;
}