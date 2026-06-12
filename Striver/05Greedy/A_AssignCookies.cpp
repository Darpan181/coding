#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findContentChildren(vector<int> &greedy, vector<int> &size){
    sort(greedy.begin(), greedy.end());
    sort(size.begin(), size.end());
    int left = 0;
    int right = 0;
    while(left < size.size() && right < greedy.size()){
        if(greedy[right] <= size[left]){
            right++;
        }
        left++;
    }
    return right;
}
int main(){
    vector<int> greedy = {1,5,3,3,4};
    vector<int> size = {4,2,1,2,1,3};
    cout<<findContentChildren(greedy, size);
return 0;
}