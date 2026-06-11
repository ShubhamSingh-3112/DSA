#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number:";
    int num;int i;
    cin>>num;
    cout<<"Enter how many bits to be cleared:";
    cin>>i;
    cout<<"Result after clearing: "<< (num & ~((1<<i)-1));
}