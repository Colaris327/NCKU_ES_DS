// 搬動陣列，讓陣列向右循環
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Original Array : ";
    for (int i = 0; i < 10; i++)
        cout << setw(2) << arr[i] << ' ';
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        int temp = arr[9];
        for (int j = 9; j >= 0; j--)
            arr[j] = arr[j - 1];
        arr[0] = temp;
        cout << "After " << setw(2) << i + 1 << " move  : ";
        for (int i = 0; i < 10; i++)
            cout << setw(2) << arr[i] << ' ';
        cout << endl;
    }
}