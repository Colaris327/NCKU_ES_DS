// 老鼠走迷宮
#include <iostream>
#include <iomanip>
using namespace std;


int step = 1;
bool rat(int board[6][6], int i, int j)
{
    if (i == 5 && j == 5)
        return true;
    if (board[i][j] == 0)
    {
        board[i][j] = step++;
        if (rat(board, i - 1, j) || rat(board, i, j + 1) || rat(board, i + 1, j) || rat(board, i, j - 1))
            return true;
        else
        {
            step--;
            board[i][j] = INT32_MIN; // 對走過但是死路的做標記
            return false;
        }
    }
    else
        return false;
}

int main()
{
    int Board[6][6] = {{-1, -1, -1, -1, -1, -1},
                    {-1, 0, -1, -1, -1, -1},
                    {-1, 0, 0, 0, 0, -1},
                    {-1, -1, 0, -1, -1, -1},
                    {-1, 0, 0, 0, 0, 0},
                    {-1, -1, -1, -1, -1, -1}};

    if (rat(Board, 1, 1))
    {
        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                if (Board[i][j] == -1)
                    cout << setw(3) << '|';
                else if (Board[i][j] == INT32_MIN)
                    cout << setw(3) << 'X';
                else
                    cout << setw(3) << Board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}