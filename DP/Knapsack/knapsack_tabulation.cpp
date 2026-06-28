#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7;
    int n = val.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt<=j){
                dp[i][j] = max(dp[i-1][j-itemWt]+itemVal,dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } cout<<endl<<"-----------------------------------"<<endl;
    }



    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}