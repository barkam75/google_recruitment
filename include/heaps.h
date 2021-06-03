#ifndef __HEAPS_DEMO__
#define __HEAPS_DEMO__
#include <vector>
using namespace std;

class MaxHeap
{
    vector<int> array;
    void swap(int index1, int index2);
    bool compare(int index1, int index2);
    bool islast(int index) { return (index * 2 + 2) >= array.size(); };

public:
    int peek(void) { return array.size() > 0 ? array[0] : -1; };
    void push(int value);
    int pop(void);
};

void heaps_demo(void);
#endif