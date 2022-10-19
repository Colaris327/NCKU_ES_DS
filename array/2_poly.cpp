#include <iostream>
using namespace std;

int main()
{
    int polyA[] = {4, 2, -6, 4, 3, 11};
    int check = polyA[1]; // 用來check係數是否全為0
    // 第一項不用印正負所以獨立出來
    if (polyA[0] > 1 && polyA[1] > 0)
        cout << polyA[1] << "x^" << polyA[0];
    for (int i = 2; i <= polyA[0]; i++)
    {
        if (polyA[i] < 0)
            cout << " - " << polyA[i] - 2 * polyA[i] << "x^" << polyA[0] + 1 - i;
        else if (polyA[i] > 0)
            cout << " + " << polyA[i] << "x^" << polyA[0] + 1 - i;
        check = polyA[i];
    }
    // 常數項不用印x所以獨立出來，另外若全部係數皆為0要印出0
    if (polyA[polyA[0] + 1] > 0)
        cout << " + " << polyA[polyA[0] + 1];
    else if (polyA[polyA[0] + 1] < 0)
        cout << " - " << polyA[polyA[0] + 1] - 2 * polyA[polyA[0] + 1];
    else if (!check)
        cout << 0;
    
}