#include<iostream>
using namespace std;

int kadens(int arr[],int n){
    int maxSum = INT32_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum = max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);
    cout << kadens(arr,n);
}