#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2,-3,6,-5,4};
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            for(int k = i;k<=j;k++){
                cout<<arr[k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}