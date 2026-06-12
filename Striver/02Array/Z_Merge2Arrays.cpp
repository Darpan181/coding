//.........................BRUTE SOLUTION..........................
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr1 = {1,3,5,7}; int n1 = arr1.size();
//     vector<int> arr2 = {0,2,6,8,9}; int n2 = arr2.size();
//     vector<int> ans;
//     int i = 0;
//     int j = 0;
//     while(i<n1 && j<n2){
//         if(arr1[i] <= arr2[j]){
//             ans.push_back(arr1[i]);
//             i++;
//         }
//         else{
//             ans.push_back(arr2[j]);
//             j++;
//         }
//     }
//     while(i < n1){
//         ans.push_back(arr1[i]);
//         i++;
//     }
//     while(j < n2){
//         ans.push_back(arr2[j]);
//         j++;
//     }

//     for(int i=0; i<ans.size(); i++){
//         if(i < n1) arr1[i] = ans[i];
//         else arr2[i - n1] = ans[i]; 
//     }
// return 0;
// }


//..........................OPTIMAL SOLUTION.........................
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr1 = {1,3,5,7}; int n1 = arr1.size();
    vector<int> arr2 = {0,2,6,8,9}; int n2 = arr2.size();
    int left = n1 - 1;
    int right = 0;
    while(left>=0 && right<n2){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    for(int i=0; i<n2; i++){
        cout<<arr2[i]<<" ";
    }
return 0;
}