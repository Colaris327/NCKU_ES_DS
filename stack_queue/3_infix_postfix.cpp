// 中序轉後序
#include <iostream>
#include <stack>
using namespace std;

// 比較priority，A>B時return true
bool Compare(char A, char B)
{
    // 多一個\n是用來方便比較的，無意義，想改成其他符號也可以
    char priority_out[] = {'\n', '+', '-', '*', '/', '('};
    char priority_stack[] = {'(', '+', '-', '*', '/'};
    int x = 0, y = 0;
    while (A != priority_out[x])
        x++;
    while (B != priority_stack[y])
        y++;
    return (x > y) ? 1 : 0;
}

int main()
{
    stack<char> st;
    char temp;
    cout << "input your function : ";
    temp = cin.get();
    while (temp != '\n')
    {
        if (temp >= 48 && temp <= 57) // 看輸入的是數字還是運算子，是數字就直接印
            cout << temp;
        else
        {
            if (st.empty())
                st.push(temp);
            else if (temp == ')')
            {
                while (st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && !Compare(temp, st.top()))
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(temp);
            }
        }
        temp = cin.get();
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}