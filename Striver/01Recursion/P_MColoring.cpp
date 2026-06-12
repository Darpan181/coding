#include<bits/stdc++.h>
using namespace std;
// bool isSafe(int node, int color[], vector<pair<int, int>> &edges, int n, int col){
//     for(int k=0; k<n; k++){
//         if(k != node && edges[k][node] == 1 && color[k] == col) return false;
//     }
//     return true;
// }
// bool solve(int node, int color[], int m, int n, vector<pair<int, int>> &edges){
//     if(node == n) return true;
//     for(int i=1; i<=m; i++){
//         if(isSafe(node, color, edges, n, i)){
//             color[node] = i;
//             if(solve(node + 1, color, m, n, edges)) return true;
//             color[node] = 0;
//         }
//     }
//     return false;
// }
int main(){
    int N = 4;
    int M = 3;
    int E = 5;
    vector<pair<int, int>> edges = {{1,2} , {2,3} , {3,4} , {4,1} , {1,3}};
    int color[N] = {0};
    //cout<<solve(1, color, M, N, edges);
return 0;
}