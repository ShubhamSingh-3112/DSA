#include<iostream>
#include<vector>
using namespace std;




int knapsack(vector<int> &val,vector<int> &wt,int w,int n,vector<vector<int>> &dp){
    if(n==0 || w==0){ 
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if (w>=wt[n-1]){
        int included = knapsack(val,wt,w-wt[n-1],n-1,dp) + val[n-1];
        int excluded = knapsack(val,wt,w,n-1,dp);
        dp[n][w] = max(included,excluded);
    }
    else{
        dp[n][w] = knapsack(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}


int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7;
    int n = val.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    cout<<knapsack(val,wt,w,val.size(),dp);
    cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}