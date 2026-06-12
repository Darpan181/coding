#include<iostream>
using namespace std;
int power(int a, int b){
    if(b==1) return a;
    int ans = power(a,b/2);
    if(b%2==0) return ans*ans;
    if(b%2!=0) return ans*ans*a;
}
int main(){
    cout<<power(2,8);
return 0;
}