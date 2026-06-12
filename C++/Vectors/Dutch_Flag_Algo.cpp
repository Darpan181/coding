                                                /*1) mid ke baare m socho
                                                  2) 0 to low-1 --> 0 ; high+1 to end --> 2
                                                  3) low to mid-1 --> 1*/
#include<iostream>
#include<vector>
using namespace std;

int display(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void sort(vector<int> &v){
    int low=0, mid=0, high=v.size()-1;
    while(mid<=high){
        if(v[mid]==2){
            int temp= v[mid];
            v[mid]= v[high];
            v[high]= temp;
            high--;
        }
        else if(v[mid]==0){
            int temp= v[mid];
            v[mid]= v[low];
            v[low]= temp;
            low++;
            mid++;
        }
        else mid++;
    }                      
}
int main()
{
    int n;
    vector<int> v;
    cout<<"Enter size of array:";
    cin>>n;
    cout<<"Enter array elements:";
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    display(v);
    sort(v);
    cout<<"\n";
    display(v);
return 0;
}