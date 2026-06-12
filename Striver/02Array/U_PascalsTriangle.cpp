//............TO PRINT A ROW OF PASCAL1S TRIANGLE...............
// #include<iostream>
// using namespace std;
// int main(){
//     int ans = 1;
//     int n = 5;
//     cout<<ans<<" ";
//     for(int i=1; i<n; i++){
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout<<ans<<" ";
//     }
// return 0;
// }

//.....................PASCAL`S TRIANGLE...................
#include<iostream>
#include<vector>
using namespace std;

int nCr(int n, int r){
    int res = 1;
    for(int i=0; i<r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main(){
    int n = 6;
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        vector<int> temp;
        for(int j=1; j<=i; j++){
            temp.push_back(nCr(i - 1, j - 1));
        }
        ans.push_back(temp);
    }
    for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
}
return 0;
}