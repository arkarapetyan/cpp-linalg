#include "linalg.h"
#include <iostream>

using namespace std;

void print_matrix(double **matrix, size_t m, size_t n);

int main()
{
    double **matrix; 
    size_t m, n;
    cin >> m >> n;

    matrix = new double*[m];
    for(size_t i = 0; i < m; i++)
    {
        matrix[i] = new double[n];
    }

    for(size_t i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    gaussian_elimination(matrix, m, n);
    print_matrix(matrix, m, n);

    for(int i = 0; i < m; i++)
    {
        delete matrix[i];
    }
    delete matrix;
}

void print_matrix(double **matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
};
