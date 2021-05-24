#include <algorithm>
#include "maxcontainer.h"

using namespace std;

void maxcontainer_brute(int numbers[], int length, int &p1, int &p2, int &maxArea)
{
    int n, m;
    maxArea = 0;
    p1 = 0;
    p2 = 0;

    for (n = 0; n < length; n++)
        for (m = n + 1; m < length; m++)
        {
            int area = min(numbers[n], numbers[m]) * (m - n);
            if (area > maxArea)
            {
                maxArea = area;
                p1 = n;
                p2 = m;
            }
        }
}

void maxcontainer_optimal(int numbers[], int length, int &p1, int &p2, int &maxArea)
{
    int cnt;
    int n = 0;
    int m = length - 1;
    maxArea = 0;

    while (n < m)
    {
        int area = min(numbers[n], numbers[m]) * (m - n);
        if (area >= maxArea)
        {
            maxArea = area;
            p1 = n;
            p2 = m;
        }
        if (numbers[n] > numbers[m])
        {
            m--;
        }
        else
        {
            n++;
        }
    }
}