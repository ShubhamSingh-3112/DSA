#include<iostream>
using namespace std;
int linear(int *arr,int n,int key){
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[20] = {
    45, 12, 78, 23, 56,
    89, 34, 67, 91, 10,
    53, 27, 84, 39, 62,
    15, 73, 48, 96, 31
};
    int key = 20;
    int n = sizeof(arr)/sizeof(int);
    cout << linear(arr,n,key);
    
}