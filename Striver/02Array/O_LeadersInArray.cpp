//...............BRUTE FORCE......................
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {10,22,12,3,0,6};
//     int n = arr.size();
//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         bool flag = true;
//         for(int j=i+1; j<n; j++){
//             if(arr[j] > arr[i]){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag == true) ans.push_back(arr[i]);
//     }
//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
// return 0;
// }


//......................OPTIMAL SOLUTION..................
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> arr = {10,22,12,3,0,6};
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;

    for(int i=n-1; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
return 0;
}