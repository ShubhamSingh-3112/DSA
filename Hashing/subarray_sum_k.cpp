#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subArraySum(vector<int> &nums,int k){
    int sum=0;
    int totalCount = 0;
    unordered_map<int ,int> sumCount;
    sumCount[0] = 1;
    for(int j=0;j<nums.size();j++){
        sum+=nums[j];
        if(sumCount.count(sum-k)){
            totalCount+=sumCount[sum-k];
        }
        if(sumCount.count(sum)){
            sumCount[sum]+=1;
        }
        else{
            sumCount[sum]=1;
        }
    }
    return totalCount;
}
int main(){
    vector<int> nums = {10,2,-2,-20,10};
    cout<<subArraySum(nums,-10);
}