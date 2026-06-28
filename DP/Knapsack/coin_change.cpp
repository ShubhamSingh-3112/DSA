#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
    }
    }
    cout<<dp[n][amount];
    
}