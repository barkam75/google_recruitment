#include <unordered_map>
#include <iostream>
using namespace std;

bool twoSum_basic(int numbers[], int length, int target, int &p1, int &p2)
{
    for (p1 = 0; p1 < length; p1++)
    {
        for (p2 = p1 + 1; p2 < length; p2++)
            if ((numbers[p1] + numbers[p2]) == target)
                return true;
    }
    return false;
}

bool twoSum_optimal(int numbers[], int length, int target, int &p1, int &p2)
{
    unordered_map<int, int> nums_map;

    for (p1 = 0; p1 < length; p1++)
    {
        if (nums_map.find(numbers[p1]) == nums_map.end())
        {
            nums_map[target - numbers[p1]] = p1;
        }
        else
        {
            p2 = nums_map[numbers[p1]];
            return true;
        }
    }
    return false;
}