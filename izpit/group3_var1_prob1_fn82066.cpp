#include <iostream>
using namespace std;

double* average(double A[][10], unsigned int rows)
{
    double* averageForRow = new double[rows];

    for (int i = 0; i < rows; i++)
    {
        averageForRow[i] = 0;
        for (int j = 0; j < 10; j++)
        {
            averageForRow[i] += A[i][j];
        }
        averageForRow[i] /= 10;
    }

    return averageForRow;
}

int main()
{
    double A[4][10] = {{3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {1.3, 2.3, 3.3, 4.3, 5.3, 6.3, 7.3, 8.3, 9.3, 10.3},
    {-1.5, 1.5, -2.1, 2.1, -3.7, 3.7, -4.2, 4.2, -5, 5}, {0, 0.1, 0.05, 0.01, 0.005, 0.001, 0.0005, 0.0001, 0.00005, 0.00001}};
    unsigned int rows = 4;

    double* result = average(A, rows);
    for (int i = 0; i < rows; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}