#include<iostream>
#include<vector>
using namespace std;

int gcd1(int a, int b) {
    for(int i = min(a,b); i>=2; i--) {
        if(a%i==0 && b%i==0) return i; 
    }
    return 1;
}

int gcd2(int a, int b) {
    if(a == 0) return b;
    return gcd2(b % a, a);
}

int main(){
    cout<<gcd1(24,48)<<endl;
    cout<<gcd2(60,72)<<endl;
}