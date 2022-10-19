#include <iostream>
using namespace std;

int main()
{
    int data[3][3];
    cout << "Input your data(row major) : ";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> data[i][j];

    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << ' ' << data[i][j];
        cout << endl;
    }

    cout << "\nDeterminat = " << data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1])
        - data[1][0] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) + data[2][0] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
    
}