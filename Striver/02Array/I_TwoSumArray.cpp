// .........BRUTE FORCE.................
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {2,6,5,8,11};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int target = 14;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i+1; j<n; j++){
//             sum = arr[i] + arr[j];
//             if(sum == target){
//                 cout<<"TRUE";
//                 return 0;
//             }
//         }
//     }
//     cout<<"FALSE";
// return 0;
// }

// ................USING HASHING.....................
// BEST WHEN WE HAVE TO RETURN INDICES
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     int arr[] = {2,6,5,8,11};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int target = 15;

//     map<int, int> mpp;
//     for(int i=0; i<n; i++){
//         int a = arr[i];
//         int more = target - a;
//         if(mpp.find(more) != mpp.end()){
//             cout<<"TRUE";
//             return 0;
//         }
//         mpp[a] = i;
//     }
//     cout<<"FALSE";
// return 0;
// }


// ............TWO POINTER APPROACH.................
// BEST WHEN WE HAVE TO RETURN YES OR NO
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v = {2,11,5,8,6 };
    int target = 19;
    sort(v.begin(), v.end());

    int left=0, right= v.size()-1;
    while(left < right){
        int sum = v[left] + v[right];
        if(sum == target){
            cout<<"TRUE";
            return 0;
        }
        else if(sum < target) left++;
        else right--;
    }
    cout<<"FALSE";
return 0;
}