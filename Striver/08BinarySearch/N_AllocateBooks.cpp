#include<bits/stdc++.h>
using namespace std;
int maxList(vector<int> &arr){
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxEle = max(arr[i], maxEle);
    }
    return maxEle;
}
long long listSum(vector<int> &arr){
    long long sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}
int countStudents(vector<int> &arr, int nop){
    int nos = 1 , pagesStudent = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] + pagesStudent <= nop){
            pagesStudent += arr[i];
        }
        else{
            nos++;
            pagesStudent = arr[i];
        }
    }
    return nos;
}
int minPages(vector<int> arr, int students){
    if(students > arr.size()) return -1;
    int low = maxList(arr);
    long long high = listSum(arr);
    int ans = high;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(countStudents(arr, mid) <= students){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> pages = {25, 46, 28, 49, 24};
    int students = 4;
    cout<<minPages(pages, students);
return 0;
}