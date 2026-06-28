#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>((amount+1),INT32_MAX));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1 , dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
    }
    }
    cout<<dp[n][amount];
    
}