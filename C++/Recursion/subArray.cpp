#include<iostream>
#include<vector>
using namespace std;

void subArray(int arr[], int n, vector<int> ans, int idx) {
    if(idx == n) {
        for(int i=0; i<ans.size(); i++) {
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    subArray(arr, n, ans, idx+1);
    if(ans.size()==0 || arr[idx-1] == ans[ans.size()-1]) {
        ans.push_back(arr[idx]);
        subArray(arr, n, ans, idx+1);
    }
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subArray(arr, n, v, 0);
return 0;
}