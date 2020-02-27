#include <iostream>
#include <cstring>
using namespace std;

void backwards(const char *s)
{
    int sLen = strlen(s);

    int firstSpace = -1;
    for (int i = 0; i < sLen; i++)
    {
        if (s[i] == ' ')
        {
            firstSpace = i;
            break;
        }
    }

    if (firstSpace == -1)
    {
        cout << s;
    }
    else
    {
        backwards(s + firstSpace + 1);
        cout << " ";
        for (int i = 0; i < firstSpace; i++)
        {
            cout << s[i];
        }
    }
}

int main()
{
    const char *s = "i love programming with cpp";
    backwards(s);

    return 0;
}