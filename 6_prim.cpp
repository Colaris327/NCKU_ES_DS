#include <iostream>
#include <fstream>
#include <utility>
#include <iomanip>
using namespace std;

class node_information
{
    public:
        int start = 0;
        int end = 0;
        int weight = 0;
        node_information() {}
        node_information(int a, int b, int c): start(a), end(b), weight(c) {}
};

int used_node[100];
int step = 0;
node_information Find_next(int **matrix, int size);

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
            if (matrix[i][j] <= 0)
                matrix[i][j] = INT32_MAX;
        }

    int total_weight = 0;
    used_node[0] = 1;
    node_information selected_node;
    for (int i = 0; i < matrix_size - 1; i++)
    {
        selected_node = Find_next(matrix, matrix_size);
        total_weight += selected_node.weight;
        cout << "Choose" << setw(3) << selected_node.start + 1 << " to" << setw(3) << selected_node.end + 1 << " weight:"
            << setw(3) << selected_node.weight << " total weight: " << setw(3) << total_weight << endl;
    }
    
    return 0;
}

node_information Find_next(int **matrix, int size)
{
    int min = INT32_MAX - 1;
    int start = 0;
    int end = 0;
    // if (step == 0)
    //     used_node[0] = 1;
    for (int i = 0; i < size; i++)
    {
        if (used_node[i] == 1)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j] < min && used_node[j] == 0)
                {
                    min = matrix[i][j];
                    start = i;
                    end = j;
                }
            }
        }
    }
    used_node[end] = 1;
    // step++;
    return node_information(start, end, min);
}