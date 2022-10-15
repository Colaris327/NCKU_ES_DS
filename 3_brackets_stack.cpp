// 判斷大中小括號是否合法
#include <iostream>
#include <stack>
using namespace std;

bool CHECK(char bracket, stack<char> & st);

int main()
{
    stack<char> BStack;
    char temp;
    bool sign = true;
    temp = cin.get();
    while (temp != '\n')
    {
        if (CHECK(temp, BStack) != true)
        {
            sign = false;
            cout << "Not good\n";
            break;
        }
        temp = cin.get();
    }
    if (BStack.empty() && sign)
        cout << "GOOD\n";
    else if (sign)
        cout << "Not good\n";
}

bool CHECK(char bracket, stack<char> & st)
{
    switch (bracket)
    {
        case ')':
            if (st.empty() != true)
            {
                char s = st.top();
                st.pop();
                return s == '(';
            }
            else
                return false;
            break;
        case ']':
            if (st.empty() != true)
            {
                char s = st.top();
                st.pop();
                return s == '[';
            }
            else
                return false;
            break;
        case '}':
            if (st.empty() != true)
            {
                char s = st.top();
                st.pop();
                return s == '{';
            }
            else
                return false;
            break;
        default:
            st.push(bracket);
            return true;
            break;
    }
}