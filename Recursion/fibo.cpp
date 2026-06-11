#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fibo(n-2)+fibo(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter n:";cin>>n;
    cout<<"Fibonacci number at "<<n<<" is:";
    cout << fibo(n);
}