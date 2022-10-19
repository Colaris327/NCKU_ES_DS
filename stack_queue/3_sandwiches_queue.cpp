// 學生排隊拿三明治，遇到不喜歡的口味就重新排隊
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int Sandwiches[100];
    int sa, stu, temp, food = 0, count = 0;
    cout << "How many sandwiches? ";
    cin >> sa;
    for (int i = 0; i < sa; i++)
    {
        cin >> temp;
        Sandwiches[i] = temp;
    }

    queue<int> Students;
    cout << "How many students? ";
    cin >> stu;
    for (int i = 0; i < stu; i++)
    {
        cin >> temp;
        Students.push(temp);
    }

    while (!Students.empty())
    {
        count++;
        temp = Students.front();
        Students.pop();
        if (temp == Sandwiches[food])
            food++;
        else
            Students.push(temp);
    }
    cout << "Count : " << count << endl;
}