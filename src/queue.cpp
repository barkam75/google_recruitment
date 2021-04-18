//FIFO Queue demo
#include <cstddef>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

static Node *head = NULL;
static Node *tail = NULL;

bool enqueue(int value)
{
    Node *element = new Node;

    if (element == NULL)
    {
        return false;
    }

    element->value = value;
    element->next = NULL;

    if (head == NULL)
    {
        head = element;
        tail = element;
    }
    else
    {
        tail->next = element;
        tail = element;
    }
    return true;
}

void dequeue(int *value)
{
    Node *element = head;
    if (element != NULL)
    {
        *value = head->value;
        head = head->next;
        delete element;
        if (head == NULL)
            tail = NULL;
    }
}

bool isEmpty(void)
{
    return head == NULL ? true : false;
}

unsigned int getSize(void)
{
    unsigned int cnt = 0;
    Node *element = head;
    while (element != NULL)
    {
        cnt++;
        element = element->next;
    }
    return cnt;
}

void flush(void)
{
    int v;
    while (!isEmpty())
        dequeue(&v);
}

//TODO: Function not working yet
bool reverse(unsigned int number)
{
    Node *element = head;
    Node *tmp;
    unsigned int cnt = number;
    while (cnt-- > 0)
    {

        if (element == NULL)
            return false;
        element = element->next;
    }
    return true;
}

/* int main(void)
{
    int v;
    cout << "List demo..." << endl;
    enqueue(1);
    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(9);
    cout << getSize() << endl;
    reverse(3);
    while (!isEmpty())
    {
        dequeue(&v);
        cout << "Dequeued element:" << v << endl;
    }
    cout << getSize() << endl;
    return 0;
} */