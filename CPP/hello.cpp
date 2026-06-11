#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int n){
    if(n==1){
        return false;
    }
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}
void print(int n){
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
}
bool palindrome(int n){
    int rev=0;
    int copy = n;
    while(copy!=0){
        int digit = copy%10;
        rev = rev*10+digit;
        copy/=10;
    }
    if(rev==n){
        return true;
    }
    else{
        return false;
    }
}
int sumOfDigits(int n){
    int sum=0;
    while(n!=0){
        int digit = n%10;
        sum+=digit;
        n/=10;
    }
    cout<<sum;
}
int greatest(int a,int b,int c){
    return a>=b? a>=c?a:c : b>=c?b:c ;
}
int main()
{
    cout<<4/2;
}