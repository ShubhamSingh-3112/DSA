#include <iostream>
using namespace std;
bool checkSorted(int arr[], int n, int i)
{
    if (i >= n - 1)
    {
        return true;
    }
    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    checkSorted(arr, n, i + 1);
}
int main()
{
    int arr[] = {1, 2, 45, 6, 3};
    cout << checkSorted(arr, 5, 0);
}