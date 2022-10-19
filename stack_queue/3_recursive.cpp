#include <iostream>
using namespace std;

// 費氏數列
int Fib(int n);
// 階乘
int Fac(int n);
// 河內塔
void Hanoi(int N, char A, char B, char C);

int main()
{
    // for (int i = 0; i < 6; i++)
    //     cout << "the " << i << " of Fibonacci sequence " << Fib(i) << endl;
    // for (int i = 0; i < 6; i++)
    //     cout << i << "! = " << Fac(i) << endl;
    Hanoi(3, 'A', 'B', 'C');
    return 0;
}

int Fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}

int Fac(int n)
{
    if (n == 0)
        return 1;
    else
        return n * Fac(n - 1);
}

void Hanoi(int N, char A, char B, char C)
{
    if (N == 1)
        cout << "move plate from " << A << " to " << C << endl;
    else
    {
        Hanoi(N - 1, A, C, B);
        cout << "move plate from " << A << " to " << C << endl;
        Hanoi(N - 1, B, A, C);
    }
}