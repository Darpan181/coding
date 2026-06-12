// Keep 3 counters
// 5 - +1
// 10 - (+10) , (-5)
// 20 - (+20) , -(10,5)  OR  (+20) , -(5,5,5)
#include<iostream>
#include<vector>
using namespace std;
bool lemonadeChange(vector<int> &arr){
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 5) five += 1;
        else if(arr[i] == 10){
            if(five){
                five -= 1;
                ten += 1;
            }
            else return false;
        }
        else{
            if(five && ten){
                ten -= 1;
                five -= 1;
            }
            else if(five >= 3) five -= 3;
            else return false;
        }
    }
    return true;
}
int main(){
    vector<int> bill = {5,5,5,10,20};
    vector<int> bills = {5,5,10,10,20};
    cout<<lemonadeChange(bill)<<endl;
    cout<<lemonadeChange(bills)<<endl;
return 0;
}