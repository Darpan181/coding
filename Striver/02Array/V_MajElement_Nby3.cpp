// CONCEPT : MORE THAN 2 ELEMENTS CANNOT BE PRESENT (N / 3 TIMES --> floor value)

//.......................BRUTE SOLUTION.............................
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {1,1,1,3,3,2,2,2};
//     int n = arr.size();
//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         if(ans.size() == 0 || ans[0] != arr[i]){
//             int cnt = 0;
//             for(int j=i; j<n; j++){
//                 if(arr[j] == arr[i]) cnt++;
//             }
//             if(cnt > n/3) ans.push_back(arr[i]);
//         }
//         if(ans.size() == 2) break;
//     }
//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
// return 0;
// }


//......................OPTIMAL SOLUTION.............................
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// int main(){
//     vector<int> arr = {1,1,1,3,3,2,2,2};
//     int n = arr.size();
//     unordered_map<int, int> mpp;
//     int mini = n/3 + 1;
//     vector<int> ans;

//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++;
//         if(mpp[arr[i]] == mini) ans.push_back(arr[i]);
//         if(ans.size() == 2) break;
//     }
//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
// return 0;
// }


//.......................BETTER SOLUTION..........................
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> arr = {1,1,1,3,3,2,2,2};
    int n = arr.size();

    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for(int i=0; i<n; i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    // MANUAL CHECK
    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;
    }
    int mini = n/3 + 1;
    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini && ele1 != ele2) ans.push_back(ele2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
return 0;
}