#include <iostream>
#include <iomanip>
using namespace std;

int **Create_Board(int size);
void Print_Board(int **Board, int size);
void Knight(int **Board, int size);
bool Knight_Direction(int **Board, int i_dir, int j_dir, int size);
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

bool Knight_Direction(int **Board, int i_dir, int j_dir, int size)
{
    if (step == size * size + 1)
        return 1;
    bool check_dir1, check_dir2, check_dir3, check_dir4, check_dir5, check_dir6, check_dir7, check_dir8;
    if (Board[i_dir][j_dir] == 0)
    {
        Board[i_dir][j_dir] = step++;
        check_dir1 = Knight_Direction(Board, i_dir - 2, j_dir + 1, size);
        check_dir2 = Knight_Direction(Board, i_dir - 1, j_dir + 2, size);
        check_dir3 = Knight_Direction(Board, i_dir + 1, j_dir + 2, size);
        check_dir4 = Knight_Direction(Board, i_dir + 2, j_dir + 1, size);
        check_dir5 = Knight_Direction(Board, i_dir + 2, j_dir - 1, size);
        check_dir6 = Knight_Direction(Board, i_dir + 1, j_dir - 2, size);
        check_dir7 = Knight_Direction(Board, i_dir - 1, j_dir - 2, size);
        check_dir8 = Knight_Direction(Board, i_dir - 2, j_dir - 1, size);
        if (check_dir1 || check_dir2 || check_dir3 || check_dir4 || check_dir5 || check_dir6 || check_dir7 || check_dir8)
            return 1;
        else
        {
            step--;
            Board[i_dir][j_dir] = 0;
            return 0;
        }
    }
    else
        return 0;
}