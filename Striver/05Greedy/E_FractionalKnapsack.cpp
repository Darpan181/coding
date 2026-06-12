#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    if( (a.first / a.second) >= (b.first / b.second) ) return true;
    return false;
}
int Knapsack(vector<pair<int,int>>&arr, int W){
    sort(arr.begin(), arr.end(), comp); 
    double totalVal = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].second <= W){
            totalVal += arr[i].first;
            W -= arr[i].second;
        }
        else{
            totalVal += (arr[i].first / arr[i].second) * W;
            break;
        }
    }
    return totalVal;
}
int main(){
    vector<pair<int,int>> arr = {{100,20}, {60,10}, {100,50}, {200,50}};
    int Weight = 90;
    cout<<Knapsack(arr, Weight); // O(N) if list is already sorted
return 0;
}