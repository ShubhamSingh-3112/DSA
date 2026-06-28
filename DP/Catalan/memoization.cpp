#include<iostream>
#include<vector>
using namespace std;
int catalan(int n,vector<int>&dp){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=catalan(i,dp)*catalan(n-i-1,dp);
    }
    return dp[n]=ans;
}
int main(){
    vector<int> dp(10,-1);
    for(int i=0;i<=6;i++){
        cout<<catalan(i,dp)<<" ";
    }
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<dp[i]<<" ";
    }
}