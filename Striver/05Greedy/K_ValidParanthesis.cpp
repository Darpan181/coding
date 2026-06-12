#include<iostream>
#include<vector>
using namespace std;
//.....................USING RECURSION...........................
// bool isValid(string str, int idx, int count){
//     if(count < 0) return false;
//     if(idx == str.length()) return (count == 0);
//     if(str[idx] == '(') return isValid(str, idx + 1, count + 1);
//     if(str[idx] == ')') return isValid(str, idx + 1, count - 1);
//     return isValid(str, idx + 1, count + 1) ||
//            isValid(str, idx + 1, count - 1) ||
//            isValid(str, idx + 1, count);
// }
bool isValid(string str){
    int min = 0;
    int max = 0; // using range concept
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            min += 1;
            max += 1;
        }
        else if(str[i] == ')'){
            min -= 1;
            max -= 1;
        }
        else{
            min -= 1;
            max += 1;
        }
        if(min < 0) min = 0;
        if(max < 0) return false;
    }
    return (min == 0);
}
int main(){
    string s = "(*))";
    // cout<<isValid(s, 0, 0);
    cout<<isValid(s);
return 0;
}