#include<iostream>
using namespace std;
void change(int arr[],int n,int i){
    if(i>=n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        return;
    }
    arr[i] = i+1;
    change(arr,n,i+1);
    arr[i]-=2;
}
int main(){
    int arr [5] = {0};
    int n = sizeof(arr) / sizeof(int);
    change(arr,n,0);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}