#include <iostream>
using namespace std;

int const MatrixSize = 5;

bool contains(char A[][MatrixSize + 1], const char *s)
{
    int sLen = 0;
    while (s[sLen] != '\0')
    {
        sLen++;
    }

    for (int r = 0; r < MatrixSize; r++)
    {
        for (int c = 0; c < MatrixSize; c++)
        {
            if (c + sLen <= MatrixSize)
            {
                bool equal = true;
                for (int i = 0; i < sLen; i++)
                {
                    if (s[i] != A[r][c + i])
                    {
                        equal = false;
                        break;
                    }
                }
                if (equal)
                {
                    return true;
                }
            }
            if (r + sLen <= MatrixSize)
            {
                bool equal = true;
                for (int i = 0; i < sLen; i++)
                {
                    if (s[i] != A[r + i][c])
                    {
                        equal = false;
                        break;
                    }
                }
                if (equal)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    char A1[MatrixSize + 1][MatrixSize + 1] = {"abgod", "rocat", "12a45", "detdo", "6do9g"};
    char s1[MatrixSize + 1] = "cat";
    cout << contains(A1, s1) << endl;
    char s2[MatrixSize + 1] = "rocat";
    cout << contains(A1, s2) << endl;
    char s3[MatrixSize + 1] = "dog";
    cout << contains(A1, s3) << endl;

    char A2[MatrixSize + 1][MatrixSize + 1] = {"gubq ", "uma i", "duma", "domat", "5eggs"};
    char s4[MatrixSize + 1] = "gud";
    cout << contains(A2, s4) << endl;
    char s5[MatrixSize + 1] = "good";
    cout << contains(A2, s5) << endl;

    return 0;
}