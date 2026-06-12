#include<bits/stdc++.h>
using namespace std;
bool hasCycle(vector<int> adj[], int v){
    vector<int> indegree(v + 1, 0);
    for(int i=1; i<=v; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1; i<=v; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == v) return false;
    else return true;
}
int main(){
    int v = 5;
    vector<int> adj[v + 1];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(2);
    
    cout<<hasCycle(adj, v); // O(V + E)
return 0;
}