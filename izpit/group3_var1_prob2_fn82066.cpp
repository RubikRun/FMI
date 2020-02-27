#include <iostream>
#include <cstring>
using namespace std;

#define CHARVALUES 256

char* unique(const char *s)
{
    int sLen = strlen(s);

    bool used[CHARVALUES];
    for (int i = 0; i < CHARVALUES; i++)
    {
        used[i] = false;
    }

    int repeats = 0;
    for (int i = 0; i < sLen; i++)
    {
        if (used[s[i]])
        {
            repeats++;
        }
        else
        {
            used[s[i]] = true;
        }
    }

    int resultLen = sLen - repeats;
    char* result = new char[resultLen];
    for (int i = 0; i < CHARVALUES; i++)
    {
        used[i] = false;
    }
    int currResultLen = 0;
    for (int i = 0; i < sLen; i++)
    {
        if (!used[s[i]])
        {
            result[currResultLen++] = s[i];
            used[s[i]] = true;
        }
    }

    return result;
}

int main()
{
    const char* s = "I love programming with cpp";
    char* r = unique(s);
    cout << r << endl;

    return 0;
}