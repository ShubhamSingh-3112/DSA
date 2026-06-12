#include<iostream>
using namespace std;
int majorityElement(int arr[],int n){
    int count = 0;
    int candidate = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==candidate){
            count+=1;
        }
        else{
            count-=1;
            if(count==0){
                candidate = arr[i];
            }
        }
    }
    return candidate;
}
int main(){
    int arr[] = {2,2,1,1,1,1,2};
    int n = sizeof(arr)/sizeof(int);
    cout << majorityElement(arr,n);
}