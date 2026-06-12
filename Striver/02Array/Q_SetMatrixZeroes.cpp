#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[3][4] = {0,1,2,0,3,4,5,2,1,3,1,5};
    int n = 3;
    int m = 4;
    int row[n] = {0};
    int col[m] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                arr[i][j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}