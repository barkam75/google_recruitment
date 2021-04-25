//data structures_demo
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "twosum.h"
#include "maxcontainer.h"
#include "rainwater.h"

using namespace std;

void stack_demo(void)
{
    int v;
    cout << "Stack demo" << endl;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    cout << "Pushed 6 items" << endl;
    while (pop(&v))
        cout << "Value:" << v << endl;
}
void queue_demo(void)
{
    int v;
    cout << "FIFO demo" << endl;
    enqueue(1);
    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(9);
    cout << getSize() << endl;
    //reverse(3);
    while (!isEmpty())
    {
        dequeue(&v);
        cout << "Dequeued element:" << v << endl;
    }
    cout << getSize() << endl;
}

void twosum_demo(void)
{
    int numbers[] = {1, 2, 8, 6, 7, 9, 11};
    int p1,
        p2;
    if (twoSum_basic(numbers, 7, 11, p1, p2))
    {
        cout << "basic" << endl;
        cout << "P1:" << p1 << " P2: " << p2 << endl;
    }

    if (twoSum_optimal(numbers, 7, 11, p1, p2))
    {
        cout << "optimal" << endl;
        cout << "P1:" << p1 << " P2: " << p2 << endl;
    }
}

void maxcontainer_demo(void)
{
    int numbers[] = {7, 1, 2, 3, 9};
    int p1, p2, area;
    maxcontainer_brute(numbers, 5, p1, p2, area);
    cout << "Max area demo (brute)" << endl;
    cout << "Max area: " << area << " by points at:(" << p1 << "," << p2 << ")" << endl;

    maxcontainer_optimal(numbers, 5, p1, p2, area);
    cout << "Max area demo (optimal)" << endl;
    cout << "Max area: " << area << " by points at:(" << p1 << "," << p2 << ")" << endl;
    cout << "Array size:" << sizeof(numbers) / sizeof(numbers[0]) << endl;
}

void rainwater_demo()
{
    //int numbers[] = {0, 3, 2, 3, 0, 3, 2, 1, 2, 9, 4, 0, 4, 3, 2, 2, 1, 3, 0};
    int numbers[] = {5, 3, 4, 5, 0, 6, 5, 4, 3, 2, 3, 4, 8};
    cout << "Trapped rainwater demo" << endl;
    cout << "Trapped water(brute):" << trapped_rainwater_brute(numbers, 13) << endl;
    cout << "Trapped water(optim):" << trapped_rainwater(numbers, 13) << endl;
}

int main(void)
{
    rainwater_demo();
    //maxcontainer_demo();
    //twosum_demo();
    // stack_demo();
    //queue_demo();
    return 0;
}