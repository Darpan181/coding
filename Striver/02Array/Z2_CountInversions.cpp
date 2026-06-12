//.......................BRUTE SOLUTION..........................
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {5,3,2,4,1};
//     int n = arr.size();
//     int count = 0;
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]) count++;
//         }
//     }
//     cout<<count;
// return 0;
// }


//........................OPTIMAL SOLUTION..........................
#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low; //starting index of left half of array
    int right = mid + 1; // starting index of right half of array

    int cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += mid - left + 1; // changes are made here
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temp to arr
    for(int i=low; i<=high; i++){
        arr[i] = temp[i - low];
    }

    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int countInversions(vector<int> &arr, int n){
    return mergeSort(arr, 0, n-1);
}
int main(){
    vector<int> arr = {5,3,2,4,1};
    int n = arr.size();
    cout<<countInversions(arr, arr.size());
}