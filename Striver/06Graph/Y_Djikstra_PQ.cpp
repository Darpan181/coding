#include<bits/stdc++.h>
using namespace std;
int main(){
    int v = 6;
    vector<pair<int, int>> adj[v];
    adj[0].push_back({1 , 4});
    adj[0].push_back({2 , 4});
    adj[1].push_back({0 , 4});
    adj[1].push_back({2 , 2});
    adj[2].push_back({0 , 4});
    adj[2].push_back({1 , 2});
    adj[2].push_back({3 , 3});
    adj[2].push_back({4 , 1});
    adj[2].push_back({5 , 6});
    adj[3].push_back({2 , 3});
    adj[3].push_back({5 , 2});
    adj[4].push_back({2 , 1});
    adj[4].push_back({5 , 3});
    adj[5].push_back({2 , 6});
    adj[5].push_back({3 , 2});
    adj[5].push_back({4 , 3});

    
}