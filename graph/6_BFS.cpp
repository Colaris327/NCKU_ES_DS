#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int used_node[100];
int BFS_seq[100];
int step = 0;

void DFS(int **matrix, int size, queue<int> & q);

int main()
{
    ifstream f;
    f.open("test.txt");
    int matrix_size, temp;
    f >> matrix_size;
    int **matrix = new int *[matrix_size];
    for (int i = 0; i < matrix_size; i++)
        matrix[i] = new int[matrix_size];
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            f >> matrix[i][j];

    used_node[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
        DFS(matrix, matrix_size, q);
    for (int i = 0; i < matrix_size; i++)
        cout << BFS_seq[i] + 1 << ' ';

    return 0;
}

void DFS(int **matrix, int size, queue<int> & q)
{
    int temp = q.front();
    BFS_seq[step] = temp;
    step++;
    q.pop();
    for (int k = 0; k < size; k++)
    {
        if (matrix[temp][k] > 0 && used_node[k] == 0)
        {
            q.push(k);
            used_node[k] = 1;
        }
    }
}