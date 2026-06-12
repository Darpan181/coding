// 1. TRANSPOSE
// 2. REVERSE EVERY ROW
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> arr;
    arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int rs = arr.size();
    int cs = arr[0].size();
    // transpose
    for(int i=0; i<rs; i++){
        for(int j=i; j<rs; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    //reverse
    int i = 0;
    while(i < rs){
        int start = 0, end = cs - 1;
        while(start < end){
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
        i++;
    }

    for(int i=0; i<rs; i++){
        for(int j=0; j<cs; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}