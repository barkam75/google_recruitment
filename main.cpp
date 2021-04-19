//data structures_demo
#include <iostream>
#include "stack.h"
#include "queue.h"

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

int main(void)
{
    stack_demo();
    queue_demo();
    return 0;
}