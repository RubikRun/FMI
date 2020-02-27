#include <iostream>
using namespace std;

const int MaxSize = 10000;

bool permutation(int a[], int b[], int size)
{
    bool used[MaxSize];
    for (int i = 0; i < size; i++)
    {
        used[i] = false;
    }

    for (int i = 0; i < size; i++)
    {
        bool found = false;
        for (int j = 0; j < size; j++)
        {
            if (!used[j] && a[i] == b[j])
            {
                used[j] = true;
                found = true;
                break;
            }
        }
        if (!found)
        {
            return false;
        }
    }

    return true;
}

bool permutationrec(int a[], int b[], int size)
{
    if (size == 0)
    {
        return true;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[size - 1] == b[i])
        {
            for (int j = i; j < size - 1; j++)
            {
                b[j] = b[j + 1];
            }
            return permutationrec(a, b, size - 1);
        }
    }

    return false;
}

int main()
{
    int a1[] = {1}, b1[] = {1};
    cout << permutation(a1, b1, 1) << " " << permutationrec(a1, b1, 1) << endl;

    int a2[] = {3, 1, 2}, b2[] = {1, 2, 3};
    cout << permutation(a2, b2, 3) << " " << permutationrec(a2, b2, 3) << endl;

    int a3[] = {1, 1, 2}, b3[] = {1, 2, 3};
    cout << permutation(a3, b3, 3) << " " << permutationrec(a3, b3, 3) << endl;

    int a4[] = {1, 3, 4, 1, 2}, b4[] = {1, 1, 2, 3, 4};
    cout << permutation(a4, b4, 5) << " " << permutationrec(a4, b4, 5) << endl;

    int a5[] = {1, 2, 3, 4, 5}, b5[] = {1, 1, 2, 3, 4};
    cout << permutation(a5, b5, 5) << " " << permutationrec(a5, b5, 5) << endl;

    return 0;
}