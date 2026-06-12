#include<iostream>
using namespace std;
void TOH(int n,char S,char D,char H){
    if(n==1){
        cout<<S<<"->"<<D<<endl;
        return;
    }
    TOH(n-1,S,H,D);
    cout<<S<<"->"<<D<<endl;
    TOH(n-1,H,D,S);
}
int main(){
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    TOH(n,'S','D','H');
return 0;
}