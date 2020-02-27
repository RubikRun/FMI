//done

#include <iostream>
using namespace std;

#define MAXSUM 3000000000

int main()
{
    int n;
    cin >> n;

    int bestM, bestP, bestQ;
    unsigned minSum = MAXSUM;
    for (int m = 1; m * m <= n; m++)
    {
        if (n % m != 0)
        {
            continue;
        }
        for (int p = 1; p * p <= n / m; p++)
        {
            if (n % (m * p) != 0)
            {
                continue;
            }
            int q = n / (m * p);

            if (m + p + q < minSum)
            {
                minSum = m + p + q;
                bestM = m;
                bestP = p;
                bestQ = q;
            }
        }
    }

    cout << bestM << " " << bestP << " " << bestQ << endl;

    return 0;
}