#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    int n = arr.size();
    unordered_map<int , int> hashset;
    hashset[0] = 1;
    int preXOR = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        preXOR = preXOR ^ arr[i];
        int x = preXOR ^ k;
        count += hashset[x];
        hashset[preXOR]++;
    }
    cout<<count;
return 0;
}