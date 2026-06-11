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
    int val;
    cout<<"Enter update bit value:";
    cin>>val;
    if(val){
        cout<<"After setting: "<<(( n | (1<<i)));
    }
    else{
        cout<<"After clearing: "<<(( n & ~(1<<i)));
    }
   
}