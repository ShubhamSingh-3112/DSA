#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {4,2,7,1,3};
    int n = nums.size();
    int target = 20;
    vector<vector<int>> dp(n+1,vector<int> (target+1,0)); 
    // row is number of elements allowed and col is target sum
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=j){
                dp[i][j] = max(dp[i-1][j-nums[i-1]]+nums[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<(dp[n][target]);
}