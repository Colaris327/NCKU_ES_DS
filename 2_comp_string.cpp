// 判斷陣列中是否存在要求的物品
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temp;
    string zoo[5] = {"bear", "cat", "gorilla", "kangaroo", "raccon"};

    cout << "What animal do you want to check? type \"exit\" for end program\n";
    cin >> temp;
    while (temp != "exit")
    {
        bool check = 0;
        for (int i = 0; i < 5; i++)
        {
            if (zoo[i] == temp)
            {
                check = 1;
                break;
            }
            else
                check = 0;
        }
        if (check)
            cout << temp << " is in the zoo!\n";
        else
            cout << "Not found\n";
        cout << "What animal do you want to check? type \"exit\" for end program\n";
        cin >> temp;
    }
}