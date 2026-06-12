#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2){
    int n= v1.size();
    int m= v2.size();
    vector<int> res(m+n);
    int i=0; //arr1
    int j=0; //arr2
    int k=0; //res
    while(i<n && j<m){
        if(v1[i]<v2[j]){
            res[k]= v1[i];
            i++;
            k++;
        }
        else{
            res[k]= v2[j];
            j++;
            k++;
        }
    }
    //for remaining
    if(i==n){   // arr1 ke saare elements utha chuke hai
        while(j<=m-1){
            res[k]= v2[j];
            k++;
            j++;
        }
    }
    if(j==m){   // arr2 ke saare elements utha chuke hai
        while(i<=n-1){
            res[k]= v1[i];
            k++;
            i++;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(4);
    arr1.push_back(5);
    arr1.push_back(8);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(6);
    arr2.push_back(7);
    arr2.push_back(10);
    arr2.push_back(12);

    vector<int> v = merge(arr1,arr2);
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
return 0;
}