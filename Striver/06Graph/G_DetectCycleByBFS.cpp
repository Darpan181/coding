#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1}); // node, parent
    while(q.empty() == false){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjacentNode : adj[node]){
            if(vis[adjacentNode] == 0){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(parent != adjacentNode) return true;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[]){
    int vis[v + 1] = {0};
    for(int i=1; i<=v; i++){
        if(vis[i] == 0){
            if(detect(i, adj, vis)) return true;// for disconnected components
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
    cout<<isCycle(V, adj); // TC : O(N + 2E)
return 0;
}