#include <iostream>
using namespace std;

void displayBoard(char board[3][3])
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char board[3][3], char player)
{

    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool isBoardFull(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void resetBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int main()
{
    char board[3][3];
    char currentPlayer;
    int row, col;
    char playAgain;

    do
    {
        resetBoard(board);
        currentPlayer = 'X';
        bool gameWon = false;

        while (!gameWon && !isBoardFull(board))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter your move row and colum (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
            {
                cout << "Invalid move. Try again" << endl;
                continue;
            }

            board[row][col] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);

            if (gameWon)
            {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins" << endl;
            }
            else if (isBoardFull(board))
            {
                displayBoard(board);
                cout << "It's a draw" << endl;
            }
            else
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
