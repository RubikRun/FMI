//done

#include <iostream>
using namespace std;

#define Digits 10

int main()
{
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    int mHas[Digits];
    for (int i = 0; i < Digits; i++)
    {
        mHas[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        mHas[m] = 1;
    }

    for (int i = a; i <= b; i++)
    {
        int iHas[Digits];
        for (int j = 0; j < Digits; j++)
        {
            iHas[j] = 0;
        }
        int tempi = i;
        while (tempi != 0)
        {
            iHas[tempi % 10] = 1;
            tempi /= 10;
        }

        bool iHasWrongDigit = false;
        for (int j = 0; j < Digits; j++)
        {
            if (iHas[j] && !mHas[j])
            {
                iHasWrongDigit = true;
                break;
            }
        }
        if (iHasWrongDigit)
        {
            continue;
        }

        cout << i << " ";
    }

    cout << endl;
}