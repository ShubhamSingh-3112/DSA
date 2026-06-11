#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number:";
    int n;
    cin>>n;
    int i;
    cout<<"Bit number:";
    cin>>i;
    cout<<"After clearing: "<<(( n & ~(1<<i)));
}