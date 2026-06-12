// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> arr = {4,3,6,2,1,1};
//     int n = arr.size();
//     vector<int> hashArr(n+1, 0);
//     for(int i=0; i<n; i++){
//         hashArr[arr[i]] += 1;
//     }
//     for(int i=1; i<n+1; i++){
//         if(hashArr[i] > 1) cout<<"Repeating = "<<i<<endl;
//         if(hashArr[i] == 0) cout<<"Missing = "<<i;
//     }
// return 0;
// }


//....................USING XOR METHOD............................
// STEP-1 => (arr[i]) ^ (1^2^3^......^n) = num
// STEP-2 => find a differentiating bit in num ; first one from right
// STEP-3 => put them in two parts and XOR
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {4,3,6,2,1,1};
    int n = arr.size();

    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }
    int bitNo = 0;
    while(1){
        if((xr & 1<<bitNo) != 0) break;
        bitNo++; // bitno pta krlia
    }
    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++){
        //part of 1 club
        if((arr[i] & 1<<bitNo) != 0){
            one = one ^ arr[i];
        }
        //part of 0 club
        else{
            zero = zero ^ arr[i];
        }
    }

    for(int i=1; i<=n; i++){
        //part of 1 club
        if((i & 1<<bitNo) != 0){
            one = one ^ i;
        }
        //part of 0 club
        else{
            zero = zero ^ i;
        }
    }
    //to verify
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == zero) cnt++;
    }
    if(cnt == 2){
        cout<<zero<<endl<<one; // repeating << missing;
        return 0;
    } 
    cout<<one<<endl<<zero;
return 0;
}