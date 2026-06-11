#include<iostream>
using namespace std;


int pow(int n,int power){ // time complexity of n
    if(power==0){
        return 1;
    }
    return n*pow(n,power-1);
}


int logPow(int n,int power){ // time complexity of log(n)
    if(power==0){
        return 1;
    }
    int half = logPow(n,power/2);
    if(power%2==0){
        return half*half;
    }
    else{
        return n*half*half;
    }
}


int main(){
    cout<<logPow(3,4);
}