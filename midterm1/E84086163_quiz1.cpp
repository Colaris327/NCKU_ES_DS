#include <iostream>

using namespace std;

int main()
{
    int temp;
    int arr[4][4];
    cout << "input the sequence :\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j = j+2)
        {
            if (i % 2 == 0)
                cout << arr[i][j] << ' ';
            else
                cout << arr[i][j+1] << ' ';
        }
    }
    
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j > 0; j = j-2)
        {
            if (i % 2 == 0)
                cout << arr[i][j] << ' ';
            else
                cout << arr[i][j-1] << ' ';
        }
    }
    return 0;
}