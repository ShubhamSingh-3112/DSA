#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<double, int> p1, pair<double, int> p2)
{
    return p1.first > p2.first;
}
void fractionalKnapsack(vector<int> val, vector<int> wt, int W)
{
    vector<pair<double, int>> ratio(val.size(), make_pair(0, 0));
    for (int i = 0; i < val.size(); i++)
    {
        double r = (double)(val[i] / wt[i]);
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare);

    int ans = 0;
    for (int i = 0; i < ratio.size(); i++)
    {
        int idx = ratio[i].second;
        if (W >= wt[idx])
        {
            ans += val[idx];
            W -= wt[idx];
        }
        else
        {
            ans += ratio[i].first * W;
            W = 0;
            break;
        }
    }
    cout << ans;
}
int main()
{
    vector<int> val = {100, 120, 60};
    vector<int> wt = {20, 30, 10};
    int W = 50;
    fractionalKnapsack(val, wt, W);
    return 0;
}