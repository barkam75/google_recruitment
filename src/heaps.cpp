#include "heaps.h"

#include <iostream>

void MaxHeap::swap(int index1, int index2)
{
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

bool MaxHeap::compare(int index1, int index2)
{
    return array[index1] >= array[index2];
}

void MaxHeap::push(int value)
{
    array.push_back(value);
    int index = array.size() - 1;
    int parent_idx;
    while (index > 0)
    {
        parent_idx = (index - 1) / 2;
        if (array[index] > array[parent_idx])
        {
            int tmp = array[index];
            array[index] = array[parent_idx];
            array[parent_idx] = tmp;
            index = parent_idx;
        }
        else
        {
            return;
        }
    }
}

int MaxHeap::pop(void)
{
    int index = 0;
    int left_idx = 1;
    int right_idx = 2;
    //Swap first and last elements
    int tmp = peek();
    swap(0, array.size() - 1);
    array.pop_back();
    //Iterate

    while (!islast(index))
    {
        if (compare(left_idx, right_idx))
        {
            if (compare(index, left_idx))
            {
                return tmp;
            }
            else
            {
                swap(index, left_idx);
                index = left_idx;
            }
        }
        else
        {
            if (compare(index, right_idx))
            {
                return tmp;
            }
            else
            {
                swap(index, right_idx);
                index = right_idx;
            }
        }
    }
    return tmp;
}

void heaps_demo(void)
{
    MaxHeap heap;
    heap.push(50);
    heap.push(45);
    heap.push(20);
    heap.push(20);
    heap.push(25);
    heap.push(15);
    heap.push(70);
    cout << "Priority queue:" << heap.pop() << endl;
    cout << "Priority queue:" << heap.pop() << endl;
    cout << "Priority queue:" << heap.pop() << endl;
}