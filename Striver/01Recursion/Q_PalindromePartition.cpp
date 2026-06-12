#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}
void func(int idx, string s, vector<string> &path, vector<vector<string>> &res){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=idx; i<s.size(); i++){
        if(isPalindrome(s, idx, i)){
            path.push_back(s.substr(idx, i - idx + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
int main(){
    string s = "aabb";
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}