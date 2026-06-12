#include<iostream>
#include<vector>
using namespace std;
int countJumps(vector<int> &arr){
    int n = arr.size();
    int jumps = 0;
    int left = 0, right = 0; // range
    while(right < n - 1){
        int farthest = 0;
        for(int i=left; i<=right; i++){
            farthest = max(i + arr[i], farthest);
        }
        left = right + 1;
        right = farthest;
        jumps += 1;
    }
    return jumps;
}
int main(){
    vector<int> arr = {2,3,1,4,1,1,1,2};
    cout<<countJumps(arr);
return 0;
}