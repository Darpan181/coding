#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(vector<int> adj[], int k){
    vector<int> indegree(k , 0);
    for(int i=0; i<k; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<k; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return ans;
}
string findOrder(vector<string>& dict, int n, int k){
    vector<int> adj[k];
    // create a graph
    for(int i=0; i<n-1; i++){
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for(int ptr=0; ptr<len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(adj, k);
    string ans = "";
    for(int i=0; i<k; i++){
        ans += (topo[i] + 'a');
    }
    return ans;
}
int main(){
    int N = 5;
    int k = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    cout<<findOrder(dict, N, k);
return 0;
}