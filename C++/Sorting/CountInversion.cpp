#include<iostream>
#include<vector>
using namespace std;
int c = 0;
int inversion(vector<int>& a, vector<int>& b){
    int count = 0;
    int i = 0;
    int j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count += (a.size() - i);
            j++;
        }
        else{// a[i]<=b[j];
            i++;
        }
    }
    return count;
}
void merge(vector<int>& a, vector<int>& b, vector<int>& res){
    int i=0, j=0, k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[i]){
            res[k++] = a[i++];
        }
        else{
            res[k++] = b[j++];
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            res[k++] = b[j++];
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            res[k++] = a[i++];
        }
    }
}
void mergeSort(vector<int>& v){
    int n = v.size();
    if(n==1) return;
    int n1 = n/2;
    int n2 = n - n/2;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0; i<n1; i++){
        a[i] = v[i];
    }
    for(int i=0; i<n2; i++){
        b[i] = v[n1+i];
    }
    mergeSort(a);
    mergeSort(b);
    //count inversions
    c += inversion(a,b);
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    cout<<c;
return 0;
}