#include<bits/stdc++.h>
using namespace std;
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathvis[]){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 0){
            if(dfsCheck(it, adj, vis, pathvis) == true) return true;
        }
        else if(pathvis[it] == 1){
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}
bool isCycle(int v, vector<int> adj[]){
    int vis[v + 1] = {0};
    int pathvis[v + 1] = {0};
    for(int i=1; i<=v; i++){
        if(vis[i] == 0){
            if(dfsCheck(i, adj, vis, pathvis) == true) return true;
        }
    }
    return false;
}
int main(){
    int V = 10;
    vector<int> adj[V + 1];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(7);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[7].push_back(5);
    adj[8].push_back(9);
    adj[9].push_back(10);
    adj[10].push_back(8);
    cout<<isCycle(V, adj);
return 0;
}