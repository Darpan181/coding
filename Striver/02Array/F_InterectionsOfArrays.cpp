#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[] = {1,2,2,3,3,4,5,6};
    int n1 = sizeof(a)/sizeof(a[0]);

    int b[] = {2,3,3,5,6,6,7};
    int n2 = sizeof(b)/sizeof(b[0]);

    vector<int> ans;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
return 0;
}