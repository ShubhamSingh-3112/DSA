#include <iostream>
using namespace std;
int main()
{
    int row, column;
    cout << "Enter rows and columns:";
    cin >> row;
    cin >> column;
    for (int i = 1; i <= row; i++)
    {
        cout<<"* "; // first default star in every column

        for(int j = 1; j<=column-2;j++){
            if(i==1||i==row){  // all spaces filled with stars fro first and last row
                cout<<"* ";
            }
            else{    // fill with empty spaces for other rows
                
                cout<<"  ";
            }
        }

        cout<<"* ";// last default star in every column
        cout << endl;
    }
}