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
string addString(string s1, string s2){
    reverse(s1);
    reverse(s2);
    int carry = 0;
    int i = 0, j = 0;
    string ans = "";
    while(i < s1.size() || j < s2.size()){
        int sum = carry;
        if(s1[i]) sum += s1[i] - '0';
        if(s2[j]) sum += s2[j] - '0';
        ans += char( (sum % 10) + '0' );
        carry = sum / 10; 
        if(i < s1.size()) i++;
        if(j < s2.size()) j++;
    }
    if(carry){
        ans += char(carry + '0');
    }
    reverse(ans);
    return ans;
}
int main(){
    string s1 = "26583";
    string s2 = "698";
    string sum = addString(s1, s2);
    cout<<sum;
return 0;
}