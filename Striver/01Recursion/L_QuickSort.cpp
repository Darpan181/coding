#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1) i++;
        while(arr[j] > pivot && j >= low + 1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
}
int main(){
    vector<int> arr = {4,6,2,5,7,9,1,3};
    quickSort(arr, 0, arr.size() - 1);
    for(int ele : arr){
        cout<<ele<<" ";
    }
return 0;
}