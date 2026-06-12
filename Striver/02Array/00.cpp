#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int n = arr.size();
    int k = 3;
    sort(arr.begin() , arr.end());
    int maxlen = 0;
    int i = 0 , j = 0;
    int sum = arr[0];
    while(j < n){
        if(sum == k){
            maxlen = max(maxlen , j - i + 1);
            sum -= arr[i];
            i++;
        }
        else if(sum < k){
            j++;
            sum += arr[j];
        }
        else{
            sum -= arr[i];
            i++;
        }
    }
    cout<<maxlen;
return 0;
}