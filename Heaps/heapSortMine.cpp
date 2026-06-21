#include<iostream>
using namespace std;
#include<vector>
void heapify(vector<int>&arr,int parent,int size){
    if(parent>=size){
        return;
    }
    int largest = parent;
    int left = 2*parent+1;
    int right = 2*parent+2;

    if(left<size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest==parent){
        return ;
    }
    swap(arr[largest],arr[parent]);
    heapify(arr,largest,size);
}
void heapSort(vector<int> &arr){
    int start = ((arr.size())/2) - 1;
    for(int i=start;i>=0;i--){
        heapify(arr,i,arr.size());
    }
    for(int i=arr.size()-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}
int main(){
    vector<int> arr = {4, 10, 3, 5, 1, 7};
    heapSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}