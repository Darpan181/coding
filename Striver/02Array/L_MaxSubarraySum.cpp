// ..................KADANE`S ALGORITHM..........
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    int maxi = INT_MIN;
    int start;
    int ansStart = -1, ansEnd = -1;

    for(int i=0; i<n; i++){
        if(sum == 0) start = i;
        sum = sum + arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    cout<<maxi<<endl;
    cout<<ansStart<<","<<ansEnd;
}