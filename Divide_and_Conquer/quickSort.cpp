#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int start,int end){
    int i = start-1;
    int pivot = arr[end];
    for(int j=start;j<=end-1;j++){
        if(arr[j]<=pivot){
            i+=1;
            swap(arr[i],arr[j]);
        }
    }
    i+=1;
    swap(arr[i],arr[end]);
    return i;
}
void quickSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivotIdx = partition(arr,start,end);
    quickSort(arr,start,pivotIdx-1);
    quickSort(arr,pivotIdx+1,end);
}
int main()
{
    vector <int> arr = {6,3,7,5,2,4,1};
    quickSort(arr,0,arr.size()-1);
    for(int i=0;i<=arr.size()-1;i++){
        cout << arr[i] << ' ';
    }
}