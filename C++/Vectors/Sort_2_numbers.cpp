#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter size of vector:";
    cin>>n;
    vector<int> v;
    cout<<"Enter array elements:";
    for(i=0;i<n;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    cout<<v.size()<<endl;
    int count0=0, count1=0;
    for(i=0;i<v.size();i++){
        if(v.at(i)==0) count0++;
        else count1++; 
    }
    for(i=0;i<count0;i++){
        v.at(i)=0;
    }
    for(i=count0;i<v.size();i++){
        v.at(i)=1;
    }
return 0;
}
