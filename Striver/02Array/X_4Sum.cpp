//...................................BRUTE SOLUTION.........................................
// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int> arr = {1,0,-1,0,-2,2};
//     int n = arr.size();
//     set<vector<int>> st;
//     int target = 0;

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 for(int l=k+1; l<n; l++){
//                     int sum = arr[i] + arr[j] + arr[k] + arr[l];
//                     if(sum == target){
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// return 0;
// }


//...........................OPTIMAL SOLUTION.....................................
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {1,1,1,3,3,5,5,4,4,4,2,2,2};
    int n = arr.size();
    int target = 8;

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i != 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j != i+1 && arr[j] == arr[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }
                else if(sum < target) k++;
                else l--; 
            }
        }
    }
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}