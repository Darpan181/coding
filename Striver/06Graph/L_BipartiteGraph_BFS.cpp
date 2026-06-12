#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
bool isCheck(int start, int v, vector<int> adj[], vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(q.empty() == false){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = ! color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int v, vector<int> adj[]){
    vector<int> color (v+1, -1);
    for(int i=1; i<=v; i++){// for disconnected graph
        if(color[i] == -1){
            if(isCheck(i, v, adj, color) == false) return false;
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