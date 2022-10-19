// 將(n-1)字串加上1後跟反向且01互換的(n-1)字串連接
#include <iostream>
#include <string>
using namespace std;

string Reverse(int n, int index, char & result)
{
    if (n == 1)
    {
        result = '0';
        return "0";
    }
    else
    {
        string temp, ans;
        string str_1 = Reverse(n - 1, 1, result);
        for (int it = str_1.size() - 1; it >= 0; it--)
        {
            if (str_1[it] == '0')
                temp += "1";
            else
                temp += "0";
        }
        ans = str_1 + "1" + temp;
        result = (ans.size() >= index) ? ans[index - 1] : 'N';
        return ans;
    }
}

int main()
{
    int N, index;
    char result;
    cout << "what is the number of string? ";
    cin >> N;
    cout << "Which index you want to see? ";
    cin >> index;
    cout << Reverse(N, index, result) << endl << result;
}