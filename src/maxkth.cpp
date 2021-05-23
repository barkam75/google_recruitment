#include <iostream>
#include "bst.h"
using namespace std;

void swap(int num[], int i, int j)
{
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
}

int partition(int num[], int left, int right)
{
    int pivot = num[right];
    int i = left;
    int j;
    for (j = left; j < right; j++)
    {
        if (num[j] < pivot)
        {
            swap(num, j, i);
            i++;
        }
    }
    swap(num, right, i);
    return i;
}

void quicksort(int num[], int left, int right)
{
    if (left < right)
    {
        int partitionIdx = partition(num, left, right);
        quicksort(num, left, partitionIdx - 1);
        quicksort(num, partitionIdx + 1, right);
    }
}

int max_kth(int num[], int length, int k)
{
    return 0;
}

int binarysearch2(int num[], int start, int end, int value)
{
    int l = start;
    int r = end;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (num[mid] == value)
            return mid;
        if (num[mid] > value)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarysearch(int num[], int length, int value)
{
    int l = 0;
    int r = length - 1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (num[mid] == value)
            return mid;
        if (num[mid] > value)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void findtarget(int num[], int length, int target, int &left_idx, int &right_idx)
{
    //Find mid
    int mid = binarysearch2(num, 0, length - 1, target);
    if (mid >= 0)
    {
        int test = mid;
        //Mid has been found
        //Find left limit
        do
        {
            left_idx = test;
            test = binarysearch2(num, 0, left_idx - 1, target);

        } while (test != -1);

        //Find right limit
        test = mid;
        do
        {
            right_idx = test;
            test = binarysearch2(num, right_idx + 1, length - 1, target);
        } while (test != -1);
    }
    else
    {
        //Target not found at all
        left_idx = -1;
        right_idx = -1;
    }
}

void sort_demo(void)
{
    int numbers[] = {5, 3, 8, 2, 9, 1, 7, 6};
    int targetnum[] = {5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 12};
    int left_idx;
    int right_idx;
    cout << "Qsort start" << endl;
    quicksort(numbers, 0, 7);
    cout << "Qsort finished" << endl;
    cout << "Element 2 is located at:" << binarysearch(numbers, 8, 4) << endl;
    cout << "Find target" << endl;

    findtarget(targetnum, 12, 5, left_idx, right_idx);
    cout << "Target is found between: " << left_idx << " and " << right_idx << " indexes" << endl;
}
