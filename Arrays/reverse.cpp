#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5};
    int start = 0;
    int n = sizeof(arr)/sizeof(int);
    int end = n - 1;
    while (start < end){
        swap(arr[start],arr[end]);
        start+=1;
        end-=1;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

}