// same as N_Meetings_in1Room concept
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
    if(a[1] < b[1]) return true;
    return false;
}
int main(){
    vector<vector<int>> intervals = {
        {0,5}, {3,4}, {1,2}, {5,9}, {5,7}, {7,9}
    };
    sort(intervals.begin(), intervals.end(), comp);
    int n = intervals.size();
    int count = 1;
    int endTime = intervals[0][1];
    for(int i=1; i<n; i++){
        if(intervals[i][0] >= endTime){
            count += 1;
            endTime = intervals[i][1];
        }
    }
    cout<<n - count;
return 0;
}