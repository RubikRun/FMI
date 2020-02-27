#include <iostream>

char* to_string(unsigned int i)
{
    if (i == 0)
    {
        char* result = new char[1];
        result[0] = '0';
        return result;
    }

    int digitsCount = 0;
    unsigned int tempi = i;
    while (tempi != 0)
    {
        tempi /= 10;
        digitsCount++;
    }

    char* result = new char[digitsCount];
    tempi = i;
    for (int k = digitsCount - 1; k >= 0; k--)
    {
        result[k] = '0' + (tempi % 10);
        tempi /= 10;
    }

    return result;
}

int main()
{
    char* r = to_string(1001);
    std::cout << r << std::endl;

    return 0;
}