#include<bits/stdc++.h>
using namespace std;
string integerToRoman(int n){
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans = "";
    for(int i=0; i<values.size(); i++){
        while(n >= values[i]){
            ans += roman[i];
            n -= values[i];
        }
    }
    return ans;
}
int main(){
    int num = 3749;
    string ans = integerToRoman(num);
    cout<<ans;
return 0;
}