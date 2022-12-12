#include <iostream>
#include <fstream>

using namespace std;

int used_node[100];
int DFS_seq[100];
int step = 0;

void DFS(int **matrix, int size, int num);

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

    DFS(matrix, matrix_size, 0);
    for (int i = 0; i < matrix_size; i++)
        cout << DFS_seq[i] + 1 << ' ';

    return 0;
}

void DFS(int **matrix, int size, int num)
{
    used_node[num] = 1;
    DFS_seq[step] = num;
    step++;
    for (int k = 0; k < size; k++)
    {
        if (matrix[num][k] > 0 && used_node[k] == 0)
        {
            DFS(matrix, size, k);
        }
    }
}