#include<iostream>
#include<vector>
using namespace std;
int catalan(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}
int main(){
    for(int i=0;i<7;i++){
        cout<<catalan(i)<<" ";
    }
}