#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool dfs(int node, int parent, int vis[], vector<int> adj[]){
    vis[node] = 1;
    for(auto adjacentNode : adj[node]){
        if(vis[adjacentNode] == 0){
            if(dfs(adjacentNode, node, vis, adj) == true) return true;
        }
        else if(adjacentNode != parent) return true;
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]){// for disconnected components
    int vis[v + 1] = {0};
    for(int i=1; i<=v; i++){
        if(vis[i] == 0){
            if(dfs(i, -1, vis, adj) == true) return true;
        }
    }
    return false;
}
int main(){
    int V = 7;
    vector<int> adj[V + 1];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(6);
    adj[4].push_back(3);
    adj[5].push_back(2);
    adj[5].push_back(7);
    adj[6].push_back(3);
    adj[6].push_back(7);
    adj[7].push_back(5);
    adj[7].push_back(6);
    cout<<isCycle(V, adj);
return 0;    
}