#include <iostream>
using namespace std;
#include <vector>
void printBoard(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------\n";
}

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    // vertical safety
    for(int j=0;j<board[0].size();j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    // horizontal safety
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    // diagonal left
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    
    // diagonal right
    for(int i=row,j=col;i>=0&&j<board[0].size();i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void nqueens(vector<vector<char>> board, int row)
{
    if (row == board.size())
    {
        printBoard(board);
        return;
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            nqueens(board, row + 1);
            board[row][j] = '.';
        }
    }
}

int main()
{
    vector<vector<char>> board;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        vector<char> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back('.');
        }
        board.push_back(v);
    }
    nqueens(board, 0);
}