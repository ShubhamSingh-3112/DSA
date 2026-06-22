#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int max_subarray(vector<int> &arr){
    unordered_map<int,int> sumIndex;
    int sum = 0;
    int length = 0;
    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        if(sumIndex.count(sum)!=0){
            length = max(length,j-sumIndex[sum]);
        }
        else{
            sumIndex[sum] = j;
        }
    }
    return length;
}
int main(){
    vector<int> arr = {15,-2,2,-8,1,7,10};
    cout<<max_subarray(arr);
}