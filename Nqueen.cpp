#include <iostream>
using namespace std;
void printqueen(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canplace(int board[][20], int n, int row, int col)
{
    //check column
    for (int i = 0; i < row; i++)
    {
        if(board[i][col]==1)
        return false;
    }
    int i=row;
    int j=col;
    //left diagonal
    while(i>=0 and j>=0){
        if(board[i][j]==1)
        return false;
        i--;j--;
    }
    i=row;
    j=col;
    //check right diagonal
    while (i>=0 and j<n)
    {
        if(board[i][j]==1)
        return false;
        i--;j++;
    }   
    //all condition then we can place queen
    return true;
}
bool solveNqueen(int board[][20], int n, int i)
{
    // base case
    if (i == n)
    {
        printqueen(board, n);
        return true;
    }
    // rec case
    // check whether we can place a queen or not
    for (int j = 0; j < n; j++)
    {
        if (canplace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNqueen(board, n, i + 1);
            if (success)
            {
                return true;
            }
            // else backtrack
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int Nqueen[20][20]={0};
    // size of board
    int n;
    cin >> n;
    solveNqueen(Nqueen, n, 0);
    return 0;

}