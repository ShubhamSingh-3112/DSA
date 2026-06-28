#include<iostream>
#include<vector>
using namespace std;
int climb_ways(int n){
    if(n==0||n==1){
        return 1;
    }
    return climb_ways(n-1) + climb_ways(n-2);
}
int climb_ways(int n,vector<int>&dp){
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = climb_ways(n-1,dp) + climb_ways(n-2,dp);
}
int tabulated(int n){
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[0] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n = 6;
    cout<<climb_ways(n);
    cout<<endl;
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    cout<<climb_ways(n,dp);
    cout<<endl;
    cout<<tabulated(n);
}