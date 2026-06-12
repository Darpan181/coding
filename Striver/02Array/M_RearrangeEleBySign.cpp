//.................BRUTE FORCE...............
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> v = {3,1,-2,-5,2,-4};
//     int n = v.size();
//     vector<int> pos;
//     vector<int> neg;

//     for(int i=0; i<n; i++){
//         if(v[i] > 0){
//             pos.push_back(v[i]);
//         }
//         else{
//             neg.push_back(v[i]);
//         }
//     }
//     for(int i=0; i<n/2; i++){
//         v[2*i] = pos[i];
//         v[2*i+1] = neg[i];
//     }

//     for(int i=0; i<n; i++){
//         cout<<v[i]<<" ";
//     }
// return 0;
// }

// POS == NEG

//.............OPTIMAL......................
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {3,1,-2,-5,2,-4};
    int n = v.size();
    vector<int> ans(n,0);
    int posIndex = 0;
    int negIndex = 1;
    for(int i=0; i<n; i++){
        if(v[i] > 0){
            ans[posIndex] = v[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = v[i];
            negIndex += 2;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
return 0;
}