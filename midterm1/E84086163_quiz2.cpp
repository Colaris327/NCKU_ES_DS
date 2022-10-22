#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int sa, stu, temp, count = 0;
    stack<int> sand;
    cout << "How many sandwiches? ";
    cin >> sa;
    cout << "sandwich sequence : ";
    for (int i = 0; i < sa; i++)
    {
        cin >> temp;
        sand.push(temp);
    }

    queue<int> Students;
    cout << "How many students? ";
    cin >> stu;
    cout << "student sequences : ";
    for (int i = 0; i < stu; i++)
    {
        cin >> temp;
        Students.push(temp);
    }

    while (!Students.empty())
    {
        count++;
        if (sand.top() == Students.front())
        {
            sand.pop();
            Students.pop();
        }
        else if (Students.front() == 2)
        {
            Students.pop();
            sand.push(0);
        }
        else if (Students.front() == 3)
        {
            Students.pop();
            sand.push(1);
        }
        else if (Students.front() == 4)
        {
            Students.pop();
            sand.pop();
            sand.pop();
        }
        else
        {
            temp = Students.front();
            Students.pop();
            Students.push(temp);
        }
    }
    cout << "Time : " << count << endl;
    return 0;
}