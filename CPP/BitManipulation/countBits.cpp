#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter num:";
    cin>>num;
    int count = 0;

    while(num){
        if(num & 1){
            count++;
        }
        num = num>>1;
    }
    
    cout<<count;
}