// Kahn`s Algorithm => topological sorting using BFS
#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(vector<int> adj[], int v){
    vector<int> indegree(v);
    for(int i=0; i<v; i++){
        for(int it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
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