#include<bits/stdc++.h>
using namespace std;
int Bsearch(vector<int> arr , int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) return Bsearch(arr, low, mid - 1, target);
    else return Bsearch(arr, mid + 1, high, target);
}
int main(){
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    cout<<Bsearch(arr, 0, arr.size() - 1, 9);
return 0;
}