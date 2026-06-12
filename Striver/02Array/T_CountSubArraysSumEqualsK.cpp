//..................BRUTE SOLUTION.................
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
//     int n = arr.size();
//     int target = 3;

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += arr[k];
//             }
//             if(sum == target) count++;
//         }
//     }
//     cout<<count;
// }


//....................OPTIMAL SOLUTION.................
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int n = arr.size();
    int target = 3;

    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        preSum += arr[i];
        int remove = preSum - target;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    cout<<cnt;
return 0;
}