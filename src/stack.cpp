//Stack subroutines
#include <iostream>

typedef struct Node Node;
struct Node
{
    int value;
    Node *prev;
};

static Node *stack = NULL;

bool push(int v)
{
    Node *element = new Node;
    if (element == NULL)
        return false;
    element->value = v;
    element->prev = stack;
    stack = element;
    return true;
}

bool peek(int *v)
{
    if (stack == NULL)
        return false;
    *v = stack->value;
    return true;
}

bool pop(int *v)
{
    Node *element = stack;
    if (!peek(v))
        return false;
    stack = stack->prev;
    delete element;
    return true;
}
