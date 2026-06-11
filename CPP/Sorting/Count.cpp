#include<iostream>
using namespace std;
int main()
{
    int arr[] ={3,2,5,1,4};
    int c[100];
    int output[5];

    for(int i=0;i<=5;i++){
        c[i]=0;
    }

    for(int i=0;i<5;i++){
        c[arr[i]]++;
    }
    
    for(int i=0;i<5;i++){
        c[i+1] = c[i]+c[i+1];
    }

    for(int i=4;i>=0;i--){
        output[c[arr[i]]-1] = arr[i];
        c[arr[i]]--;
    }
    for(int i=0;i<5;i++){
        cout<<output[i]<<" ";
    }
}