//done

#include <iostream>
#include <cstring>
#include <string.h>
#include <sstream>
using namespace std;

#define MaxUnitLen 2
#define MaxStringSize 1000

void ReduceCm(double& value, char valueUnit[])
{
    if (value >= 50000)
    {
        value /= 100000;
        strcpy(valueUnit, "km");
    }
    else if (value >= 50)
    {
        value /= 100;
        strcpy(valueUnit, "m");
    }
    else
    {
        strcpy(valueUnit, "cm");
    }
}

void ReduceG(double& value, char valueUnit[])
{
    if (value >= 500000)
    {
        value /= 1000000;
        strcpy(valueUnit, "t");
    }
    else if (value >= 500)
    {
        value /= 1000;
        strcpy(valueUnit, "kg");
    }
    else
    {
        strcpy(valueUnit, "g");
    }
}

bool Convert(int value, char valueUnit[], double& targetValue, char targetValueUnit[])
{
    if (strcmp(valueUnit, "in") == 0)
    {
        targetValue = value * 2.54;
        ReduceCm(targetValue, targetValueUnit);
        return true;
    }
    else if (strcmp(valueUnit, "ft") == 0)
    {
        targetValue = value * 30.48;
        ReduceCm(targetValue, targetValueUnit);
        return true;
    }
    else if (strcmp(valueUnit, "yd") == 0)
    {
        targetValue = value * 91.44;
        ReduceCm(targetValue, targetValueUnit);
        return true;
    }   
    else if (strcmp(valueUnit, "mi") == 0)
    {
        targetValue = value * 160934;
        ReduceCm(targetValue, targetValueUnit);
        return true;
    }
    else if (strcmp(valueUnit, "oz") == 0)
    {
        targetValue = value * 28.3495;
        ReduceG(targetValue, targetValueUnit);
        return true;
    }
    else if (strcmp(valueUnit, "lb") == 0)
    {
        targetValue = value * 453.592;
        ReduceG(targetValue, targetValueUnit);
        return true;
    }
    return false;
}

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

string DoubleToString(double x)
{
    stringstream stream;
    stream << x;
    return stream.str();
}

void BuildConvertedString(char str[], char targetStr[])
{
    int strSize = strlen(str);
    int targetStrSize = 0;

    int nBegin = -1;
    for (int i = 0; i < strSize; i++)
    {
        if (nBegin == -1 && IsDigit(str[i]))
        {
            nBegin = i;
        }
        else if (nBegin != -1 && !IsDigit(str[i]))
        {
            if (i + 1 < strSize)
            {
                int value = StringToNumber(str, nBegin, i - 1);
                char valueUnit[] = {str[i], str[i + 1], '\0'};
                double targetValue;
                char targetValueUnit[MaxUnitLen + 1];
                if (Convert(value, valueUnit, targetValue, targetValueUnit))
                {
                    targetStrSize -= i - nBegin;
                    string targetValueStr = DoubleToString(targetValue);
                    for (int j = 0; j < targetValueStr.length(); j++)
                    {
                        targetStr[targetStrSize++] = targetValueStr[j];
                    }
                    for (int j = 0; j < strlen(targetValueUnit); j++)
                    {
                        targetStr[targetStrSize++] = targetValueUnit[j];
                    }
                    i++;
                    nBegin = -1;
                    continue;
                }
            }
            nBegin = -1;
        }
        targetStr[targetStrSize++] = str[i];
    }
    targetStr[targetStrSize++] = '\0';
}

int main()
{
    char givenString[MaxStringSize];
    cin.getline(givenString, MaxStringSize);

    char convertedString[MaxStringSize];
    BuildConvertedString(givenString, convertedString);

    cout << convertedString << endl;

    return 0;
}