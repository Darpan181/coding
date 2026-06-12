#include<bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> adj[numCourses];
    for(auto it : prerequisites){
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(numCourses, 0);
    for(int i=0; i<numCourses; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == numCourses) return true;
    return false;
}
int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout<<canFinish(numCourses, prerequisites);
return 0;
}