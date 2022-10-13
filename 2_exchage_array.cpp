// 將負數放到陣列左側，正數在陣列右側
#include <iostream>
#include <iomanip>
using namespace std;

void SWAP(int & x, int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int arr[10] = {1, -2, -3, 4, 5, -6, -7, 8, 9, 10};
    cout << "Original array : ";
    for (int i = 0; i < 10; i++)
        cout << setw(3) << arr[i];
    cout << endl;

    int left = 0, right = 9;
    while (1)
    {
        while(left < 10 && arr[left] < 0)
            left++;
        while(right >= 0 && arr [right] > 0)
            right--;
        if (left < right)
            break;
        SWAP(arr[left], arr[right]);
    }

    cout << "Adjusted array : ";
    for (int i = 0; i < 10; i++)
        cout << setw(3) << arr[i];
    cout << endl;
}