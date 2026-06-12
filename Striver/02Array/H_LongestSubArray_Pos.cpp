// <<<<<<  IF ARRAY CONTAIN NEGATIVE ELEMENTS  >>>>>>>
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     int arr[] = {1,2,3,1,1,1,1,4,2,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 3;
//     map<int, int> preSumMap;
//     int sum = 0;
//     int maxlen = 0;
//     for(int i=0; i<n; i++){
//         sum += arr[i];
//         if(sum==k) maxlen = max(maxlen, i+1);
//         int rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxlen = max(maxlen, len);
//         }
//         if(preSumMap.find(sum) == preSumMap.end()){  // does not exist in map
//             preSumMap[sum] = i;
//         }
//     }
//     cout<<maxlen;
// }

#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    int left=0, right=0;
    int sum = arr[0];
    int maxlen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    cout<<maxlen;
return 0;
}