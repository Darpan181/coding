// delay the job to the end always
// maximise the profit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(vector<int> &arr1, vector<int> &arr2){
    if(arr1[2] >= arr2[2]) return true;
    else return false;
}
pair<int,int> JobSequence(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end(), comp);
    int totalProfit = 0;
    int count = 0; // total jobs finished
    int maxDeadline = -1;
    for(int i=0; i<arr.size(); i++){
        maxDeadline = max( arr[i][1], maxDeadline); 
    }
    vector<int> hash (maxDeadline + 1, -1);
    for(int i=0; i<arr.size(); i++){
        for(int j=arr[i][1]; j>=0; j--){
            if(hash[j] == -1){
                count += 1;
                hash[j] = arr[i][0];
                totalProfit += arr[i][2];
                break; 
            }
        }
    }
    return {totalProfit, count};
}
int main(){
    vector<vector<int>> jobs = {// ID, Deadline, Profit
        {1,4,20}, {2,5,60}, {3,6,70}, {4,6,65}, {5,4,25}, {6,2,80}, 
        {7,2,10}, {8,2,22}
    };    
    pair<int,int> ans = JobSequence(jobs); // TC : O( N2 )
    cout<<"("<<ans.first<<","<<ans.second<<")";
return 0;
}