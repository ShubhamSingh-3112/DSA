#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s1 = "abedge";
    string s2 = "abcdg";
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout <<  ans;
}