// print elements appearing more than N/2 times

// ..................BRUTE FORCE..................
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {2,2,3,3,1,2,2};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i<n; i++){
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j] == arr[i]) count++;
//         }
//         if(count > n/2){
//             cout<<arr[i]<<endl;
//             break;
//         }
//     }
// return 0;
// }


// ...............BY HASHING(MAP)  <ele, count>..........
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     map<int, int> mpp;
//     int arr[] = {2,2,3,3,1,2,2};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it: mpp){
//         if(it.second > n/2){
//             cout<<it.first;
//         }
//     }
// return 0;
// }


// ............MOORE`S VOTING ALGORITHM...............
#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,2,3,3,1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int count = 0;
    int ele;
    for(int i=0; i<n; i++){
        if(count == 0){
            count = 1;
            ele = arr[i];
        }
        else if(arr[i] == ele) count++;
        else count--;
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele) cnt++;//this step occurs if array might not have the majority element.
    }
    if(cnt > n/2) cout<<ele;
    else cout<<"-1";
return 0;
}