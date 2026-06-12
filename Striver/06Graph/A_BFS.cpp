#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
vector<int> bfs(int v, vector<int> adj[]){
    int vis[v] = {0}; // 0 based graph 
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while( !q.empty() ){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){
            if( !vis[it] ){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}// Time Complexity : O( V + 2E )

int main() {
    int V = 6;  
    vector<int> adj[V];  

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    vector<int> result = bfs(V, adj);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}