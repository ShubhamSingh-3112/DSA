#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5};
    int key = 3;
    int start = 0;
    int end = (sizeof(arr)/sizeof(int)) - 1;
    while(start<=end){
        int mid = (start + end)/2;
        // cout << arr[mid] << endl;
        if(arr[mid] == key){
            cout << mid << ' ';
            break;
        }
        else if (arr[mid]>key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
}