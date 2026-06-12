#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x,i,j;
    cout<<"Enter target: ";
    cin>>x;
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
    for(i=0;i<n;i++){
        cout<<v.at(i)<<" ";
        cout<<endl;
    }
    for(i=0;i<=n-2;i++){
        for(j=i+1;j<n;j++){
            if(v[i]+v[j]==x){
                cout<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }
return 0;
}