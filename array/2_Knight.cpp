#include <iostream>
#include <iomanip>
using namespace std;

int **Create_Board(int size);
void Print_Board(int **Board, int size);
void Knight(int **Board, int size);
bool Knight_Direction(int **Board, int x_dir, int y_dir, int size);
int step = 1;

int main()
{
    int size;
    cout << "What is the size of board ? ";
    cin >> size;
    int **Board = Create_Board(size);
    Knight(Board, size);
}

int **Create_Board(int size)
{
    int **Board = new int *[size + 4];
    for (int i = 0; i < size + 4; i++)
        Board[i] = new int[size + 4];
    for (int i = 0; i < size + 4; i++)
        for (int j = 0; j < size + 4; j++)
            Board[i][j] = -1;
    for (int i = 2; i < size + 2; i++)
        for (int j = 2; j < size + 2; j++)
            Board[i][j] = 0;
    return Board;
}

void Print_Board(int **Board, int size)
{
    cout << endl;
    for (int i = 2; i < size + 2; i++)
    {
        for (int j = 2; j < size + 2; j++)
            cout << setw(3) << Board[i][j];
        cout << endl;
    }
}

void Knight(int **Board, int size)
{
    bool result = 0;
    result = Knight_Direction(Board, 2, 2, size);
    if (result)
        Print_Board(Board, size);
    else
        cout << "Failed\n";
}

// I mistake using x_dir and y_dir, so there is a little confused about my code.
// The problem is using i_dir and j_dir might be more clear.
bool Knight_Direction(int **Board, int x_dir, int y_dir, int size)
{
    if (step == size * size + 1)
        return 1;
    bool check_dir1, check_dir2, check_dir3, check_dir4, check_dir5, check_dir6, check_dir7, check_dir8;
    if (Board[y_dir][x_dir] == 0)
    {
        Board[y_dir][x_dir] = step++;
        check_dir1 = Knight_Direction(Board, x_dir + 1, y_dir - 2, size);
        check_dir2 = Knight_Direction(Board, x_dir + 2, y_dir - 1, size);
        check_dir3 = Knight_Direction(Board, x_dir + 2, y_dir + 1, size);
        check_dir4 = Knight_Direction(Board, x_dir + 1, y_dir + 2, size);
        check_dir5 = Knight_Direction(Board, x_dir - 1, y_dir + 2, size);
        check_dir6 = Knight_Direction(Board, x_dir - 2, y_dir + 1, size);
        check_dir7 = Knight_Direction(Board, x_dir - 2, y_dir - 1, size);
        check_dir8 = Knight_Direction(Board, x_dir - 1, y_dir - 2, size);
        if (check_dir1 || check_dir2 || check_dir3 || check_dir4 || check_dir5 || check_dir6 || check_dir7 || check_dir8)
            return 1;
        else
        {
            step--;
            Board[y_dir][x_dir] = 0;
            return 0;
        }
    }
    else
        return 0;
}