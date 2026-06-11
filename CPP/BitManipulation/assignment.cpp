#include <iostream>
using namespace std;
int main()
{
    // int nums [] = {1,1,2,2,3,3,4,5,5};
    // int ans = 0;
    // for(int i=0;i<9;i++){
    //     ans = ans ^ nums[i];
    // }
    // cout<<ans;
    int dividend = 15;
    int divisor = 3;
    int i = 1;
    while(divisor){
        if(divisor & 1 ){
            dividend = dividend - divisor;
        }
        divisor = divisor >> 1;
        i++;
    }
    cout<<dividend;
}