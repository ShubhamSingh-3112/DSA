#include<iostream>
using namespace std;
int modified_binary_search(int arr[],int start,int end,int target){
    if(start>end){
        return -1;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[start]<=arr[mid]){ //Line 1
        if(target>=arr[start] && target<arr[mid]){
            return modified_binary_search(arr,start,mid-1,target); // search in left half
        }
        else{
            return modified_binary_search(arr,mid+1,end,target); // search in right half
        }
    }
    else{
        if(target>arr[mid] && target<=arr[end]){ // Line 2
            return modified_binary_search(arr,mid+1,end,target); // search in right half
        }
        else{
            return modified_binary_search(arr,start,mid-1,target);//search in left half
        }
    }
}
int main()
{
    int arr[] = {4,5,6,7,0,1,2};
    int target = 9;
    int n = sizeof(arr)/sizeof(int);
    cout << modified_binary_search(arr,0,n-1,target);
}