#include<iostream>
#include<vector>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr){
    int i = 0;
    for(int j=i+1; j<arr.size(); j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return arr;
}
int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
    arr = removeDuplicate(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
return 0;
}