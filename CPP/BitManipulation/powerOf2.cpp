#include <iostream>
using namespace std;
int main()
{
    cout << "Enter number:";
    int n;
    cin >> n;
    if ((n & (n - 1)))
    {
        cout << "Not a power of 2";
    }
    else
    {
        cout << "power of 2";
    }
}
