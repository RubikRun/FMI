//done

#include <iostream>
#include <cstring>
using namespace std;

#define MaxDigits 100

void ReverseDigits(char digits[], int digitsCount)
{
    for (int i = 0; i <= digitsCount - 1 - i; i++)
    {
        int t = digits[i];
        digits[i] = digits[digitsCount - 1 - i];
        digits[digitsCount - 1 - i] = t;
    }
}

void ValueToDigits(int value, char digits[], int& digitsCount, int base)
{
    digitsCount = 0;
    while (value != 0)
    {
        digits[digitsCount++] = (value % base) + '0';
        value /= base;
    }
    ReverseDigits(digits, digitsCount);
}

int DigitsToValue(char digits[], int digitsCount, int base)
{
    int value = 0;
    for (int i = 0; i < digitsCount; i++)
    {
        value *= base;
        value += digits[i] - '0';
    }
    return value;
}

int main()
{
    char nBasePDigits[MaxDigits];
    cin >> nBasePDigits;
    int nBasePDigitsCount = strlen(nBasePDigits);

    int baseP, baseQ;
    cin >> baseP >> baseQ;

    int nValue = DigitsToValue(nBasePDigits, nBasePDigitsCount, baseP);
    
    char nBaseQDigits[MaxDigits];
    int nBaseQDigitsCount;
    ValueToDigits(nValue, nBaseQDigits, nBaseQDigitsCount, baseQ);

    for (int i = 0; i < nBaseQDigitsCount; i++)
    {
        cout << nBaseQDigits[i];
    }
    cout << endl;

    return 0;
}