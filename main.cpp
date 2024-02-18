#include "linalg.h"
#include <iostream>

using namespace std;

void print_matrix(double **matrix, size_t m, size_t n);

int main()
{
    double **matrix;
    size_t m, n;
    char c;
    bool use_optimal = false;    

    while (true)
    {
        cout << "Input Matrix Size (m n): ";
        cin >> m >> n;

        matrix = new double *[m];
        for (size_t i = 0; i < m; i++)
        {
            matrix[i] = new double[n];
        }

        cout << "Input Matrix Like So: " << endl;
        cout << "1 2 3" << endl;
        cout << "4 5 6" << endl;
        cout << "7 8 9" << endl;
        cout << endl;

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        cout << endl;
        cout << "Use optimal pivot search [y / n]: ";
        cin >> c;

        if(c == 'y')
        {
            use_optimal = true;
        }

        gaussian_elimination(matrix, m, n, use_optimal);

        cout << endl;
        print_matrix(matrix, m, n);
        cout << endl;

        for (size_t i = 0; i < m; i++)
        {
            delete matrix[i];
        }
        delete matrix;
    }   
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
