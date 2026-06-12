    #include<bits/stdc++.h>
    using namespace std;
    vector<int> PrefixMax(vector<int> &arr){
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for(int i=1; i<n; i++){
            pre[i] = max(arr[i], pre[i-1]);
        }
        return pre;
    }
    vector<int> SuffixMax(vector<int> &arr){
        int n = arr.size();
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i] = max(arr[i], suff[i+1]);
        }
        return suff;
    }
    int trap(vector<int> &arr){
        int total = 0 , n = arr.size();
        vector<int> prefixmax = PrefixMax(arr);
        vector<int> suffixmax = SuffixMax(arr);
        for(int i=0; i<n; i++){
            int leftmax = prefixmax[i] , rightmax = suffixmax[i];
            if(arr[i] < leftmax && arr[i] < rightmax){
                total += min(leftmax, rightmax) - arr[i];
            }
        }
        return total;
    }
    int main(){
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout<<trap(height);
    return 0;
    }