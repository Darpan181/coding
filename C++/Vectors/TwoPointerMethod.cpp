#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &v){
    int n=v.size();
    int i=0, j=n-1;
    while(i<j){
        if(v[i]<0) i++;
        if(v[j]>0) j--;
        else if(v[i]>0 && v[j]<0){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
    }
}
int display(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main()
{
    int i,j,n;
    vector<int> v;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array elements:-";
    for(i=0;i<n;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    sort(v);
    display(v);
return 0;
}