#ifndef __QUEUE_ON_STACKS__
#define __QUEUE_ON_STACKS__

struct StackNode
{
    int value;
    StackNode *prev;
};
class Queue
{
private:
    StackNode *stack1;
    StackNode *stack2;
    StackNode *push(StackNode *&stack, int value);
    bool pop(StackNode *&stack, int &value);

public:
    Queue();
    StackNode *enqueue(int value);
    bool dequeue(int &value);
    StackNode *peek(void);
    void empty(void);
};

#endif