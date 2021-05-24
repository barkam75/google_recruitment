#include <iostream>
#include "queue_on_stacks.h"

Queue::Queue()
{
    stack1 = NULL;
    stack2 = NULL;
}
StackNode *Queue::push(StackNode *&stack, int value)
{
    StackNode *item = new StackNode;
    if (item != NULL)
    {
        item->value = value;
        item->prev = stack;
        stack = item;
    }
    return item;
}

bool Queue::pop(StackNode *&stack, int &value)
{
    StackNode *item = stack;
    if (item != NULL)
    {
        stack = stack->prev;
        value = item->value;
        delete item;
        return true;
    }
    return false;
}

StackNode *Queue::enqueue(int value)
{
    return push(stack1, value);
}

bool Queue::dequeue(int &value)
{
    if (stack2 == NULL)
    {
        int v;
        while (pop(stack1, v))
        {
            push(stack2, v);
        }
        return pop(stack2, value);
    }
    else
    {
        return pop(stack2, value);
    }
}

StackNode *Queue::peek(void)
{
    if (stack2 == NULL)
    {
        int v;
        while (pop(stack1, v))
        {
            push(stack2, v);
        }
    }
    return stack2;
}

void Queue::empty(void)
{
    int v;
    while (pop(stack1, v))
        ;
    while (pop(stack2, v))
        ;
}
