//done

#include <iostream>
using namespace std;

#define MAXN 100000

int arr[MAXN];

bool BinSearch(int first, int last, int target)
{
    if (first == last)
    {
        return (arr[first] == target);
    }

    int middle = (first + last) / 2;
    return (BinSearch(first, middle, target) || BinSearch(middle + 1, last, target));
}

int main()
{
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int pairsCount = 0;
    for (int i = 0; arr[i] <= x - arr[i]; i++)
    {
        if (BinSearch(i, n - 1, x - arr[i]))
        {
            pairsCount++;
        }
    }

    cout << pairsCount << endl;

    return 0;
}