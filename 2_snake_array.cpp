// 二維陣列，奇數列順向輸出，偶數列逆向輸出
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int arr[10][10];
    int count = 1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr[i][j] = count++;

    cout << "Original :\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << setw(3) << arr[i][j] << ' ';
        cout << endl;
    }

    cout << "Snake Version :\n";
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < 10; j++)
                cout << setw(3) << arr[i][j] << ' ';
        else
            for (int j = 9; j >= 0; j--)
                cout << setw(3) << arr[i][j] << ' ';
        cout << endl;
    }
}