#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &a){
    int i;
    for(i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
}
int main(){
    int i,j;
    vector<int> v;
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(i=0;i<n;i++){
       int q;
       cin>>q;
       v.push_back(q); 
    }
    cout<<"Reversed Array:"<<endl;
    for(i=0,j=n-1;i<j;i++,j--){
        int temp= v.at(i);
        v.at(i)= v.at(j);
        v.at(j)= temp;
    }
    display(v);
return 0;
}