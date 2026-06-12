#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool dfs(int node, vector<int> adj[], int vis[], int pathvis[]){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : adj[node]){
        //when node is visited
        if(vis[it] == 0){
            if(dfs(it, adj, vis, pathvis) == true) return true;
        }
        //node has been visited
        //and visited on the same path
        else if(pathvis[it]){
            return true;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]){
    int vis[v+1] = {0};
    int pathvis[v+1] = {0};
    for(int i=1; i<=v; i++){
        if(vis[i] == 0){
            if(dfs(i, adj, vis, pathvis) == true) return true;
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