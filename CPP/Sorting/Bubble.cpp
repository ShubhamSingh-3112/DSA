#include <iostream>
using namespace std;
int main()
{
    int arr[] = {5, 3, 4, 6, 1};
    for (int i = 0; i < 4; i++)
    {
        bool swapped = false;
        cout<<"outer"<<endl;
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped)
        {
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}