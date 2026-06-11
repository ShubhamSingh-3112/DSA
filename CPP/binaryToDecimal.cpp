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
        int digit = n%10;
        sum+=digit*pow(2,i);
        n/=10;
        i++;
    }
    cout<<sum;
}