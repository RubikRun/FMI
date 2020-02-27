//done

#include <iostream>
using namespace std;

#define MAXN 1000

int main()
{
    int n;
    cin >> n;

    int h[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int maxWater = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int water = (j - i) * min(h[i], h[j]);
            if (water > maxWater)
            {
                maxWater = water;
            }
        }
    }

    cout << maxWater << "000" << endl;

    return 0;
}