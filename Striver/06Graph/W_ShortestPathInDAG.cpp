// 1. do a topo sort on the graph
// 2. take the nodes out of stack & relax the edges
#include<bits/stdc++.h>
using namespace std;
void topo(int node, vector<pair<int, int>> adj[], int vis[], stack<int>& st){
    vis[node] = 1;
    for(auto it : adj[node]){
        int v = it.first;
        if(vis[v] == 0) topo(v, adj, vis, st);
    }
    st.push(node);
}
vector<int> findShortestDist(int v, int e, vector<pair<int, int>> adj[], int src){
    int vis[v] = {0};
    stack<int> st;
    for(int i=0; i<v; i++){
        if(vis[i] == 0) topo(i, adj ,vis, st);
    }
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}
int main(){
    int v = 7;
    int e = 8;
    int src = 6;
    vector<pair<int, int>> adj[v];
    adj[0].push_back({1 , 2});
    adj[1].push_back({3 , 1});
    adj[2].push_back({3 , 3});
    adj[4].push_back({0 , 3});
    adj[4].push_back({2 , 1});
    adj[5].push_back({4 , 1});
    adj[6].push_back({4 , 2});
    adj[6].push_back({5 , 3});

    vector<int> ans = findShortestDist(v, e, adj, src); // O(V + E)
    for(auto it : ans){
        cout<<it<<" ";
    }
return 0;
}