#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minmPlatforms(vector<int> &arr, vector<int> &dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0;
    int j = 0;
    int n = arr.size();
    int count = 0, maxCount = 0;
    while(i < n){
        if(arr[i] < dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount = max( count, maxCount );
    }
    return maxCount;
}
int main(){
    vector<int> arrvl = {900, 945, 955, 1100, 1500, 1800};
    vector<int> deprt = {920, 1200, 1130, 1150, 1900, 2000};
    cout<<minmPlatforms(arrvl, deprt);
return 0;
}