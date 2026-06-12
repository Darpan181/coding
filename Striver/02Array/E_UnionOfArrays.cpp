#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr1[] = {1,1,2,3,4,5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2,3,4,4,5,6};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    vector<int> unionArr;
    int i=0 , j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    for(int i=0; i<unionArr.size(); i++){
        cout<<unionArr[i]<<" ";
    }
return 0;
}