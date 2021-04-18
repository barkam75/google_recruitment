//data structures_demo
#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
    int v;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    cout << "Hello world!!!!" << endl;
    while (pop(&v))
        cout << "Value:" << v << endl;

    //cout << "Stack:" << stack << endl;
    return 0;
}