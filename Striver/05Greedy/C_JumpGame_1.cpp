#include<iostream>
#include<vector>
using namespace std;
bool jumpGame(vector<int> &arr){
    int maxIdx = 0;
    for(int i=0; i<arr.size(); i++){
        if(i > maxIdx) return false;
        maxIdx = max(maxIdx, i + arr[i]);
    }
    return true;
}
int main(){
    vector<int> arr = {1,2,3,1,1,0,2,5};
    cout<<jumpGame(arr);
return 0;
}