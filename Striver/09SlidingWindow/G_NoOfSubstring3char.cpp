#include<bits/stdc++.h>
using namespace std;
/*...................BRUTE SOLUTION.........................
int NoOfSubstrings(string s){
    int count = 0 , n = s.size();
    for(int i=0; i<n; i++){
        vector<int> hash(3, 0);
        for(int j=i; j<n; j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                count++;
            }
        }
    }
    return count;
}
*/

//.........................OPTIMAL SOLUTION............................
int NoOfSubstrings(string s){
    int n = s.size() , count = 0;
    int lastSeen[3] = {-1, -1, -1};
    for(int i=0; i<n; i++){
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            count += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
    }
    return count;
}
int main(){
    string s = "bbacba";
    cout<<NoOfSubstrings(s);
return 0;
}