#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
void bfs(int v, vector<int> adj[], int vis[], int start){
    queue<int> q;
    q.push(start);
    while(q.empty() == false){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}
int NoOfProvinces(int v, vector<int> adj[]){
    int count = 0;
    int vis[v + 1] = {0};
    for(int i=1; i<=v+1; i++){
        if(vis[i] == 0){
            count += 1;
            bfs(v, adj, vis, i);
        }
    }
    return count;
}
int main(){
    int V = 8;
    vector<int> adj[V + 1]; // 1 based
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[7].push_back(8);
    cout<<NoOfProvinces(V, adj);
return 0;
}