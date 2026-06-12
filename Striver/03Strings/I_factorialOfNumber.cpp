#include<bits/stdc++.h>
using namespace std;
void reverse(string &s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return;
}
string multiply(string s, int n){
    int carry = 0;
    string res = "";
    for(int i=s.size()-1; i>=0; i--){
        int prod = (s[i] - '0') * n + carry;
        res += (prod % 10) + '0';
        carry = prod / 10;
    }
    while(carry){
        res += (carry % 10) + '0';
        carry = carry / 10;
    }
    reverse(res);
    return res;
}
string factorial(int n){
    string ans = "1";
    for(int i=2; i<=n; i++){
        ans = multiply(ans, i);
    }
    return ans;
}
int main(){
    int num = 10;
    string ans = factorial(num);
    cout<<ans;
return 0;
}