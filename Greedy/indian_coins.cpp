#include<iostream>
using namespace std;
int main(){
    int coins[] = {2000,500,100,50,20,10,5,2,1};
    int amount = 2145;
    int i = 0;
    int count = 0;
    while(amount>0){
        if(amount>=coins[i]){
            cout<<"Note Used:"<<coins[i]<<endl;
            count += amount/coins[i];
            amount = amount%coins[i];
        }
        else{
            i+=1;
        }
    }
    cout<<count;
}