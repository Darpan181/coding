#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[] = {3,1,2,5,4,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int pge[n];
    pge[0] = -1;
    stack<int> st;
    st.push(arr[0]);
    //forward traversal
    for(int i=1; i<n; i++){
        while(st.size()>0 && st.top()<=arr[i]){//pop
            st.pop();
        }
        if(st.size()==0) pge[i] = -1;//ans
        else pge[i] = st.top();
        st.push(arr[i]);//push
    }
    for(int i=0; i<n; i++){
        cout<<pge[i]<<" ";
    }
    cout<<endl;
return 0;
}