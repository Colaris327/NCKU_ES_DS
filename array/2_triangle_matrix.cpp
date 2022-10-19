// 只印上三角跟下三角矩陣
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int mat[5][5] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};
    cout << "upper triangle:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < i; k++)
            cout << "   ";
        for (int j = i; j < 5; j++)
            cout << setw(3) << mat[i][j];
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            cout << setw(3) << mat[i][j];
    cout << endl;

    cout << "\nlower triangle:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(3) << mat[i][j];
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= i; j++)
            cout << setw(3) << mat[i][j];
    cout << endl;
    return 0;
}