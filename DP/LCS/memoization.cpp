#include<iostream>
#include<vector>
using namespace std;
int lcs(string str1,string str2,vector<vector<int>>&dp){
    if(str1.size()==0||str2.size()==0){
        return 0;
    }
    int n = str1.size();
    int m = str2.size();
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(str1[n-1]==str2[m-1]){
        dp[n][m] =  1 + lcs(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }
    else{
        dp[n][m] = max(lcs(str1.substr(0,n-1),str2,dp),lcs(str1,str2.substr(0,m-1),dp));
    }
    return dp[n][m];
}
int main(){
    string s1 = "abcdge";
    string s2 = "abcdg";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<lcs(s1,s2,dp);
}