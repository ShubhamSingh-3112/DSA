#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    vector<int> arr = {50,3,10,7,40,80};
    set<int> s(arr.begin(),arr.end()); // unique + sorted
    vector<int> arr2(s.begin(),s.end());
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1]==arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout <<  dp[n][m];
}