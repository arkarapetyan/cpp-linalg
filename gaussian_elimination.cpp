#include "linalg.h"
#include <cmath>
#include <iostream>

using namespace std;

int column_non_zero_index(double **matrix, size_t m, size_t start, size_t c);
int column_min_non_zero_index(double **matrix, size_t m, size_t start, size_t c);
void eliminate_column(double **matrix, size_t m, size_t n, size_t pivot, size_t c);
void interchange_rows(double *r1, double *r2, size_t n);
void multiply_row(double *r, size_t n, double coef);
void add_row_multiple(double *r1, double *r2, size_t n, double coef);

void gaussian_elimination(double **matrix, size_t m, size_t n, bool optimal_pivots)
{
    int i;
    size_t r = 0;

    for (size_t c = 0; c < n; c++)
    {
        if (optimal_pivots)
        {
            i = column_min_non_zero_index(matrix, m, r, c); // Find the minimal pivot
        }
        else
        {
            i = column_non_zero_index(matrix, m, r, c); // Find the first Non-Zero Entry
        }

        if (i == -1) // Column not Pivotal
        {
            if (r == 0)
            {
                cout << "Invalid Matrix" << endl;
                return;
            }
            continue;
        }

        if (i != r)
        {
            interchange_rows(matrix[i], matrix[r], n); // Move the Non-Zero entry to the pivot place
        }
        if (optimal_pivots && matrix[r][c] < 0) //Make the Pivot Positive
        {
            multiply_row(matrix[r], n, -1.0);
        }

        eliminate_column(matrix, m, n, r, c); // Eliminate other Column Entries
        r++;                                  // Proceed to the next row
    }
};

int column_non_zero_index(double **matrix, size_t m, size_t start, size_t c)
{
    for (size_t k = start + 1; k < m; k++)
    {
        if (matrix[k][c] != 0)
        {
            return k;
        }
    }

    return -1;
};

int column_min_non_zero_index(double **matrix, size_t m, size_t start, size_t c)
{
    int n_i = -1, n = 0;

    for (size_t k = start; k < m; k++)
    {
        if (matrix[k][c] == 0)
        {
            continue;
        }

        if ((abs(matrix[k][c]) < abs(n)) || n == 0)
        {
            n_i = k;
            n = matrix[k][c];
        }
    }

    return n_i;
};

void eliminate_column(double **matrix, size_t m, size_t n, size_t pivot, size_t c)
{
    for (size_t k = pivot + 1; k < m; k++)
    {
        if (matrix[k][c] == 0)
        {
            continue;
        }

        double coef = -(matrix[k][c] / matrix[pivot][c]);
        add_row_multiple(matrix[k], matrix[pivot], n, coef);
    }
}

void interchange_rows(double *r1, double *r2, size_t n)
{
    double t;
    for (size_t k = 0; k < n; k++)
    {
        t = r1[k];
        r1[k] = r2[k];
        r2[k] = t;
    }
};

void multiply_row(double *r, size_t n, double coef)
{
    for (size_t k = 0; k < n; k++)
    {
        if(r[k] != 0) // Avoid -0.0
        {
            r[k] = coef * r[k];
        }        
    }
};

void add_row_multiple(double *r1, double *r2, size_t n, double coef)
{
    for (size_t k = 0; k < n; k++)
    {
        if(r2[k] != 0) // Avoid -0.0
        {
            r1[k] += coef * r2[k];
        }        
    }
};
