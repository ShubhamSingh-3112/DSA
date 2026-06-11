#include<iostream>
using namespace std;
void sellStocks(int arr[],int n){
    int bestBuy[n];

    bestBuy[0] = INT32_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i] = min(bestBuy[i-1],arr[i-1]);
    }

    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int profit = 0;
        profit = arr[i] - bestBuy[i];
        maxProfit = max(maxProfit,profit);
    }
    
    cout << maxProfit;
}
int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(int);
    sellStocks(arr,n);
    return 0;
}