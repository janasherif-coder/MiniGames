#include <iostream>
using namespace std;

void display(char grid[3][3], char player)
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " | ";
        }
        if (i < 2)
        {
            cout << "\n----+---+----" << endl;
        }
        else
        {
            cout << "\n-------------" << endl;
        }
    }
    cout << "Player " << player << " Enter your move (row and column): ";
}

bool ValidMove(int row, int col, char grid[3][3])
{
    if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != '-')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool CheckWin(char grid[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
        {
            return true;
        }
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
        {
            return true;
        }
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
    {
        return true;
    }
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
    {
        return true;
    }
    return false;
}

bool CheckDraw(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

void XO_GAME()
{
    int row, col;

    char grid[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}},
         player = 'X';

    while (true)
    {
        display(grid, player);
        cin >> row >> col;
        row--;
        col--;

        if (ValidMove(row, col, grid))
        {
            grid[row][col] = player;
            if (CheckWin(grid, player))
            {
                cout << "Player " << player << " wins!" << endl;
                return; // because function here is void
            }
            if (CheckDraw(grid))
            {
                cout << "It's a draw!" << endl;
                return;
            }
            player = (player == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "Invalid Move" << endl;
        }
    }
}

int main()
{

    XO_GAME();
    cout << "1.Play again!\n"
         << "2.Exit!" << endl;
    int choice;
    cin >> choice;
    while (choice != 2)
    {
        XO_GAME();
    }
    return 0;
}