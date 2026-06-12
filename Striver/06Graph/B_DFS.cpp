#include<iostream>
#include<vector>
#include<list>
using namespace std;
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(vis[it] == 0){
            dfs(it, adj, vis, ans);
        }
    }
}
vector<int> dfs(int v, vector<int> adj[]){
    int vis[v + 1] = {0};
    int start = 3;
    vector<int> ans;
    dfs(start, adj, vis, ans);
    return ans;
}// Time Complexity : O( V + 2E )
int main(){
    int V = 8;
    vector<int> adj[V + 1];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(7);
    adj[4].push_back(3);
    adj[4].push_back(8);
    adj[5].push_back(2);
    adj[6].push_back(2);
    adj[7].push_back(3);
    adj[7].push_back(8);
    adj[8].push_back(4);
    adj[8].push_back(7);

    vector<int> result = dfs(V, adj);
    for(auto it : result){
        cout<<it<<" ";
    }
return 0;
}