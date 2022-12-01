#include <iostream>
#include <fstream>
using namespace std;

int used_node[100];
int topo[100];
int step = 0;

void Topology(int **matrix, int size);
int find(int **matrix, int size, int point);

int main()
{
    ifstream f;
    f.open("tp2.txt");
    int matrix_size, temp;
    f >> matrix_size;
    int **matrix = new int *[matrix_size];
    for (int i = 0; i < matrix_size; i++)
        matrix[i] = new int[matrix_size];
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            f >> matrix[i][j];
    for (int k = 0; k < matrix_size; k++) 
        Topology(matrix, matrix_size);
    for (int i = 0; i < matrix_size; i++)
            cout << topo[i] + 1 << ' ';
}

void Topology(int **matrix, int size)
{
    int choosed_point = 0;
    for (int i = 0; i < size; i++)
    {
        if (used_node[i] == 0 && find(matrix, size, i))
        {
            choosed_point = i;
            break;
        }
    }
    used_node[choosed_point] = 1;
    topo[step] = choosed_point;
    step++;
    for (int i = 0; i < size; i++)
        matrix[choosed_point][i] = 0;
}

int find(int **matrix, int size, int point)
{
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][point] != 0)
            flag = false;
    }
    return flag;
}