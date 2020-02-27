#include <iostream>
using namespace std;

struct Event
{
    int startTime, endTime;
};

void Merge(Event* events, int left, int middle, int right)
{
    int leftHalfSize = middle - left + 1;
    int rightHalfSize = right - middle;
    Event* leftHalf = new Event[leftHalfSize];
    Event* rightHalf = new Event[rightHalfSize];
    for (int i = 0; i < leftHalfSize; i++)
    {
        leftHalf[i] = events[left + i];
    }
    for (int i = 0; i < rightHalfSize; i++)
    {
        rightHalf[i] = events[middle + 1 + i];
    }

    int leftCurr = 0, rightCurr = 0, eventsCurr = 0;
    while (leftCurr < leftHalfSize && rightCurr < rightHalfSize)
    {
        //Sorting by endTime
        if (leftHalf[leftCurr].endTime < rightHalf[rightCurr].endTime)
        {
            events[left + (eventsCurr++)] = leftHalf[leftCurr++];
        }
        else
        {
            events[left + (eventsCurr++)] = rightHalf[rightCurr++];
        }
    }

    while (leftCurr < leftHalfSize)
    {
        events[left + (eventsCurr++)] = leftHalf[leftCurr++];
    }
    while (rightCurr < rightHalfSize)
    {
        events[left + (eventsCurr++)] = rightHalf[rightCurr++];
    }
}

void MergeSort(Event* events, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = (left + right) / 2;
    MergeSort(events, left, middle);
    MergeSort(events, middle + 1, right);
    Merge(events, left, middle, right);
}

int main()
{
    int n;
    cin >> n;

    Event* events = new Event[n];
    for (int i = 0; i < n; i++)
    {
        cin >> events[i].startTime >> events[i].endTime;
    }
    MergeSort(events, 0, n - 1);

    int nextEventIndex = 0, lastEventEndTime = 0, attendedEvents = 0;
    while (nextEventIndex < n)
    {
        while (events[nextEventIndex].startTime <= lastEventEndTime && nextEventIndex < n)
        {
            nextEventIndex++;
        }
        if (nextEventIndex >= n)
        {
            break;
        }

        lastEventEndTime = events[nextEventIndex].endTime;
        attendedEvents++;
    }

    cout << attendedEvents << endl;

    return 0;
}