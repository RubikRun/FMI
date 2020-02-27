#include <iostream>
using namespace std;

#define LightOn(n) if (!lights[n]) {cout << "+" << n << endl; lights[n] = true;}
#define LightOff(n) if (lights[n]) {cout << "-" << n << endl; lights[n] = false;}

void TurnOn(bool* lights, int n);
void TurnOff(bool* lights, int n);

void TurnOn(bool* lights, int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        LightOn(1)
        return;
    }
    if (n == 2)
    {
        LightOn(1)
        LightOn(2)
        return;
    }

    TurnOn(lights, n - 1);
    TurnOff(lights, n - 2);
    LightOn(n)
    TurnOn(lights, n - 2);
}

void TurnOff(bool* lights, int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        LightOff(1)
        return;
    }
    if (n == 2)
    {
        if (lights[1])
        {
            LightOff(2)
            LightOff(1)
        }
        else if (lights[2])
        {
            LightOn(1)
            LightOff(2)
            LightOff(1)
        }
        return;
    }

    if (!lights[n])
    {
        TurnOff(lights, n - 1);
        return;
    }

    TurnOn(lights, n - 1);
    TurnOff(lights, n - 2);
    LightOff(n)
    TurnOff(lights, n - 1);
}

int main()
{
    int n;
    cin >> n;

    bool* lights = new bool[n + 1];
    for (int i = 1; i <= n; i++)
    {
        lights[i] = false;
    }

    TurnOn(lights, n);
}