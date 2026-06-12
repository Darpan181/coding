// sort on the basis of END in increasing order
// then check the appropriate interval
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class data{
public:
    int start;
    int end;
    int pos;
};
bool comp(const data &a, const data &b){
    if(a.end <= b.end) return true;
    return false;
}
int main(){
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};
    int n = start.size();
    vector<data> arr(n);
    for(int i=0; i<n; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr.begin(), arr.end(), comp); 
    int count = 1;
    int freeTime = arr[0].end;
    vector<int> order;
    order.push_back(arr[0].pos);
    for(int i=1; i<n; i++){
        if(arr[i].start > freeTime){
            count += 1;
            freeTime = arr[i].end;
            order.push_back(arr[i].pos);
        }
    }
    cout<<count<<endl;
    for(int ele : order){
        cout<<ele<<" ";
    }
return 0;
}