#ifndef __QUEUE_ON_STACKS__
#define __QUEUE_ON_STACKS__
#include "stack.h"

class Queue
{
public:
    Node *stack1;
    Node *stack2;
    Node *enqueue(int value);
    Node *dequeue(int &value);
    Node *peek();
    void empty();
}

#endif