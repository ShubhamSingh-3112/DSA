#include<iostream>
#include<vector>
using namespace std;
int mcm(vector<int>&arr, int i,int j,vector<vector<int>> &dp){
    if(i==j){ // single matrix
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT32_MAX;
    for(int k=i;k<j;k++){
        int costLeft = mcm(arr,i,k,dp);   // left side of partition
        int costRight = mcm(arr,k+1,j,dp); // right side
        int curCost = costLeft+costRight+(arr[i-1]*arr[k]*arr[j]); //total
        ans = min(ans,curCost);
    }
    return dp[i][j] = ans;
}
int main(){
    vector<int> arr = {1,2,3,4,3};
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
    cout<<mcm(arr,1,arr.size()-1,dp); 
}