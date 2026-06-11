#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int maxsum = -1000000;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxsum = max(maxsum,sum);
        }
    }
    cout << maxsum << endl;
    // optimised brute force
    maxsum = INT32_MIN;
    for (int i = 0; i < 6; i++)
    {
        int sum = 0;
        for (int j = i; j < 6; j++)
        {
            sum+=arr[j];
            maxsum = max(maxsum,sum);
        }
    }
    cout << maxsum;
}