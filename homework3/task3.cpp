#include <iostream>
#include <cstring>
using namespace std;

char* replace(char* source, char* oldWord, char* newWord)
{
    int sourceLen = strlen(source);
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    int maxResultLen = sourceLen;
    if (newWordLen > oldWordLen)
    {
        maxResultLen = (sourceLen / oldWordLen) * newWordLen + sourceLen % oldWordLen;
    }
    char* result = new char[maxResultLen + 1];

    int resultLen = 0;
    for (int i = 0; i < sourceLen; i++)
    {
        if (i + oldWordLen > sourceLen)
        {
            result[resultLen++] = source[i];
            continue;
        }

        bool match = true;
        for (int j = 0; j < oldWordLen; j++)
        {
            if (source[i + j] != oldWord[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            for (int j = 0; j < newWordLen; j++)
            {
                result[resultLen++] = newWord[j];
            }
            i += oldWordLen - 1;
        }
        else
        {
            result[resultLen++] = source[i];
        }
    }
    result[resultLen] = '\0';

    return result;
}

char* remove(char* source, char* word)
{
    int sourceLen = strlen(source);
    int wordLen = strlen(word);

    char* result = new char[sourceLen];
    int resultLen = 0;
    for (int i = 0; i < sourceLen; i++)
    {
        if (i + wordLen > sourceLen)
        {
            result[resultLen++] = source[i];
            continue;
        }

        bool match = true;
        for (int j = 0; j < wordLen; j++)
        {
            if (source[i + j] != word[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            int wordBegin = i, wordEnd = i + wordLen - 1;
            if (wordBegin - 1 >= 0 && wordEnd + 1 < sourceLen && source[wordBegin - 1] == ' ' && (source[wordEnd + 1] == ' ' || source[wordEnd + 1] == '.'))
            {
                i = wordEnd + 1;
            }
        }
        else
        {
            result[resultLen++] = source[i];
        }
    }
    result[resultLen] = '\0';

    return result;
}