//done

#include <iostream>
#include <cstring>
using namespace std;

#define MaxStringSize 1000

bool IsDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int StringToNumber(char str[], int first, int last)
{
    int result = 0;
    for (int i = first; i <= last; i++)
    {
        result *= 10;
        result += str[i] - '0';
    }
    return result;
}

void FilterNumbersFromString(char str[], int numbers[], int& numbersCount)
{
    int strSize = strlen(str);
    numbersCount = 0;

    int nBegin = -1;
    for (int i = 0; i < strSize; i++)
    {
        if (nBegin == -1 && IsDigit(str[i]))
        {
            nBegin = i;
        }
        else if (nBegin != -1 && !IsDigit(str[i]))
        {
            numbers[numbersCount++] = StringToNumber(str, nBegin, i - 1);
            if (nBegin > 0 && str[nBegin - 1] == '-' && (nBegin == 1 || str[nBegin - 2] == ' '))
            {
                numbers[numbersCount - 1] *= (-1);
            }
            nBegin = -1;
        }
    }
    if (nBegin != -1)
    {
        numbers[numbersCount++] = StringToNumber(str, nBegin, strSize - 1);
        if (nBegin > 0 && str[nBegin - 1] == '-' && (nBegin == 1 || str[nBegin - 2] == ' '))
        {
            numbers[numbersCount - 1] *= (-1);
        }
    }
}

int main()
{
    char givenString[MaxStringSize];
    cin.getline(givenString, MaxStringSize);

    int numbers[MaxStringSize / 2], numbersCount;
    FilterNumbersFromString(givenString, numbers, numbersCount);

    int maxNumber = numbers[0];
    for (int i = 1; i < numbersCount; i++)
    {
        maxNumber = max(maxNumber, numbers[i]);
    }

    cout << maxNumber << endl;

    return 0;
}
