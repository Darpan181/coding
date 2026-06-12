//....................BETTER SOLUTION..........................
// #include<iostream>
// #include<vector>
// #include<climits>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int> arr = {5,8,3,2,1,4};
//     int n = arr.size();
//     int longest = 1;
//     int count = 0;
//     int lastSmaller = INT_MIN;

//     sort(arr.begin(), arr.end());
//     for(int i=0; i<n; i++){
//         if(arr[i] - 1 == lastSmaller){
//             count++;
//             lastSmaller = arr[i];
//         }
//         else if(lastSmaller != arr[i]){
//             count = 1;
//             lastSmaller = arr[i];
//         }
//         longest = max(longest, count);
//     }
//     cout<<longest;
// return 0;
// }


//....................OPTIMAL SOLUTION.......................
#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;
int main(){
    vector<int> arr = {5,8,3,2,1,4};
    int n = arr.size();
    unordered_set<int> st;
    int longest = 1;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){// element present nhi h
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    cout<<longest;
return 0;
}