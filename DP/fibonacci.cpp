#include<iostream>
#include<vector>
using namespace std;
int fib(int n,vector<int>&arr){
    if(n==0||n==1){
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    arr[n] = fib(n-1,arr) + fib(n-2,arr);
    return arr[n];
}
int fib_tabulated(int n){
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2;i<=n;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
    return fib[n];
}
int main(){
    vector<int>arr(6+1,-1);
    cout<<fib(6,arr);
    cout<<fib_tabulated(6);
}