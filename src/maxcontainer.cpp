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