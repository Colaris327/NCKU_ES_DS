#include <iostream>
#include <fstream>
using namespace std;

// distanse from source to other vertex
int dist[100];
int used_node[100];
int Dijk(int **matrix, int point, int size);

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
        {
            f >> matrix[i][j];
            if (matrix[i][j] == -1)
                matrix[i][j] = INT16_MAX;
        }
    for (int i = 0; i < matrix_size; i++)
        dist[i] = matrix[0][i];
    used_node[0] = 1;

    int choosed_point = 0;
    for (int i = 0; i < matrix_size - 1; i++)
    {
        choosed_point = Dijk(matrix, choosed_point, matrix_size);
    }
    for (int i = 1; i < matrix_size; i++)
        cout << "The shortest path distance from 1 to " << i + 1 << " : " << dist[i] << endl;
    
    return 0;
}

int Dijk(int **matrix, int point, int size)
{
    if (point)
    {
        for (int k = 0; k < size; k++)
        {
            if (matrix[point][k] > 0 && used_node[k] != 1 && matrix[point][k] + dist[point] < dist[k])
                dist[k] = matrix[point][k] + dist[point];
        }
    }
    int min_point = 0, min = INT32_MAX;
    for (int i = 0; i < size; i++)
        if (used_node[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            min_point = i;
        }
    used_node[min_point] = 1;
    return min_point;
}