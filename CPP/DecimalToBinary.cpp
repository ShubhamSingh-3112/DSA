#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout<<"enter n:";
    cin>>n;
    int sum=0;
    int i=0;
    while(n!=0){
        int digit = n%2;
        sum=sum+digit*round(pow(10,i));
        n /= 2;
        i++;
    }
    cout<<sum;
}