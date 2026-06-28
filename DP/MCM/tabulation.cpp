#include<iostream>
#include<vector>
using namespace std;
int mcm(vector<int>&arr){
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),INT32_MAX));
    int n = arr.size();
    for(int i=0;i<arr.size();i++){
        dp[i][i] = 0;
    }
    for(int length = 2;length<n;length++){
        for(int i=1;i<=n-length;i++){
            int j = i + length - 1;
            for(int k=i;k<j;k++){
                int leftCost = dp[i][k];
                int rightCost = dp[k+1][j];
                int total = leftCost+rightCost+arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j],total);
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    vector<int> arr = {1,2,3,4,3};
    cout<<mcm(arr);
}