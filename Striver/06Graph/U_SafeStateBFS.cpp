// reverse all the edges
#include<bits/stdc++.h>
using namespace std;
vector<int> findSafeNode(vector<int> adj[], int v){
    vector<int> adjRev[v];
    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> safeNode;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNode.push_back(node);
        for(auto it : adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    sort(safeNode.begin() , safeNode.end());
    return safeNode;
}
int main(){
    int v = 8;
    vector<int> adj[v];
    adj[0].push_back(1);
    adj[0].push_back(2);   
    adj[1].push_back(3);   
    adj[1].push_back(2);   
    adj[2].push_back(5);   
    adj[3].push_back(0);   
    adj[4].push_back(5);   
    adj[7].push_back(1);

    vector<int> ans = findSafeNode(adj, v);
    for(int it : ans){
        cout<<it<<" ";
    }   
return 0;
}