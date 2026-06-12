#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool dfs(int start, int col, vector<int> adj[], vector<int>&color){
    color[start] = col;
    for(auto it : adj[start]){
        if(color[it] == -1){
            if(dfs(it, ! col, adj, color) == false) return false;
        }
        else if(color[it] == col){
            return false;
        }
    }
    return true;
}
bool isBipartite(int v, vector<int> adj[]){
    vector<int> color (v+1, -1);
    for(int i=1; i<=v; i++){
        if(color[i] == -1){
            if(dfs(i, 0, adj, color) == false) return false;
        }
    }
    return true;
}
int main(){
    int V = 8;
    vector<int> adj[V + 1];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(6);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[4].push_back(7);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(2);
    adj[6].push_back(5);
    adj[7].push_back(4);
    adj[7].push_back(8);
    adj[8].push_back(7);
    cout<<isBipartite(V, adj);
return 0;  
}