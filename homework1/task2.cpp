//done

#include <iostream>
using namespace std;

#define MAXN 10000
#define MAXM 10000

int p[MAXN], q[MAXM];

int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        cin >> p[i];
    }

    int m;
    cin >> m;
    for (int i = m; i >= 0; i--)
    {
        cin >> q[i];
    }

    for (int k = n + m; k >= 0; k--)
    {
        int pq = 0;
        for (int i = k - m; i <= k; i++)
        {
            pq += p[i] * q[k -i];
        }
        cout << pq << " ";
    }
    cout << endl;

    return 0;
}