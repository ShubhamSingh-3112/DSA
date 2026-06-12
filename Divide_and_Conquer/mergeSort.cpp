#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int end){
    // int mid = (start+end)/2;
    int mid = start + (end-start)/2;// to prevent overflow
    int i = start;
    int j = mid+1;
    vector <int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int i=0;i<temp.size();i++){
        arr[start+i]=temp[i];
    }
}

void mergeSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}

int main(){
    vector <int> arr = {6,3,7,5,2,4,1};
    mergeSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }
}