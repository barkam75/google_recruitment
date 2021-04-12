//Stack demo
#include <iostream>
using namespace std;

typedef struct Node Node;
struct Node
{
    int value;
    Node *prev;
};

Node *stack = NULL;

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

bool pop(int *v)
{
    Node *element = stack;
    if (stack == NULL)
        return false;
    stack = element->prev;
    *v = element->value;
    delete element;
    return true;
}

int main(void)
{
    int v;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    std::cout << "Hello world!!!!" << endl;
    while (pop(&v))
        cout << "Value:" << v << endl;

    cout << "Stack:" << stack << endl;
    return 0;
}
