#include<bits/stdc++.h>
using namespace std;
//..............................MEMOIZATION.......................................
int maxPoints(vector<vector<int>>& arr, int day, int last, vector<vector<int>>& dp){
    if(day == 0){
        int maxi = 0;
        for(int i=0; i<=2; i++){
            if(i != last) maxi = max(maxi, arr[0][i]);
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0, points;
    for(int i=0; i<=2; i++){
        if(i != last){
            points = arr[day][i] + maxPoints(arr, day - 1, i, dp);
            maxi = max(maxi , points);
        }
    }
    return dp[day][last] = maxi;
}

//.............................TABULATION.....................................
int maxPointsTab(int n, vector<vector<int>>& arr){
    vector<vector<int>> dp(n , vector<int>(4 , 0));

    dp[0][0] = max(arr[0][1] , arr[0][2]);
    dp[0][1] = max(arr[0][0] , arr[0][2]);
    dp[0][2] = max(arr[0][0] , arr[0][1]);
    dp[0][3] = max(arr[0][0] , max(arr[0][1] , arr[0][2]));

    for(int day=1; day<n; day++){
        for(int last=0; last<=3; last++){
            dp[day][last] = 0;

            for(int task=0; task<3; task++){
                if(task != last){
                    int point = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last] , point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int main(){
    vector<vector<int>> arr = { // task0 task1 task2
        {2,1,3}, {3,4,6}, {10,1,6}, {8,3,7}
    };
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int> (4 , -1));
    //cout<<maxPoints(arr, n-1, 3, dp); // 3 -> no task performed
    cout<<maxPointsTab(n , arr);
return 0;
}