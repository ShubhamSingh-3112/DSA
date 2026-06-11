#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number:";
    int n;
    cin>>n;
    if(n & 1){
        cout<<"Odd";
    }
    else{
        cout<<"Even";
    }
}