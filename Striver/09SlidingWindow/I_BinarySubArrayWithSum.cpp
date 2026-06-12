// sum == goal = f(nums, goal) - f(nums, goal - 1)
#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &arr, int goal){
    if(goal < 0) return 0;
    int l = 0 , r = 0;
    int sum = 0 , count = 0;
    while(r < arr.size()){
        sum += arr[r];
        while(sum > goal){
            sum -= arr[l];
            l++;
        }
        if(sum <= goal){
            count += r - l + 1;
        }
        r++;
    }
    return count;
}
int numSubArrayWithSum(vector<int> &arr, int goal){
    return func(arr, goal) - func(arr, goal - 1);
}
int main(){
    vector<int> arr = {1, 0, 1, 0, 1};
    cout<<numSubArrayWithSum(arr, 2);
return 0;
}