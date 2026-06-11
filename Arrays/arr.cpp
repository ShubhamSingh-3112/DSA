#include<iostream>
using namespace std;
void fun(int *a){
    cout << sizeof(a);
}
int main(){
    int arr[5] = {4,3,5,2,1};
    cout<<sizeof(arr)<<endl;
    fun(arr);
    // int largest = 0;
    // for(int i=0;i<5;i++){
    //     if(arr[i]>largest){
    //         largest = arr[i];
    //     }
    // }
    // cout<<largest;
}