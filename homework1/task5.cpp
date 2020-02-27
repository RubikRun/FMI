//done

#include <iostream>
using namespace std;

#define MAXN 1000

int MaxOfInterval(int arr[], int first, int last)
{
    int result = -1;
    for (int i = first; i <= last; i++)
    {
        result = max(result, arr[i]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    int h[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int totalWater = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int leftMax = MaxOfInterval(h, 0, i);
        int rightMax = MaxOfInterval(h, i + 1, n - 1);
        int height = min(leftMax, rightMax);
        totalWater += height;
    }
    cout << totalWater << endl;

    return 0;
}