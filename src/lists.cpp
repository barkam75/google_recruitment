#include <set>
#include "lists.h"

static Node *head = NULL;
static Node *tail = NULL;

Node *append(int value)
{
    Node *item = new Node;
    if (item != NULL)
    {
        item->value = value;
        item->next = NULL;
        if (head == NULL)
        {
            head = item;
            tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
    }
    return item;
}
void print_list()
{
    Node *item = head;
    int cnt = 0;
    while (item != NULL)
    {
        cout << "Node(" << cnt << "):" << item->value << endl;
        cnt++;
        item = item->next;
    }
    cout << "Head value:" << head->value << endl;
    cout << "Tail value:" << tail->value << endl;
}

void list_full_reverse(void)
{
    Node *item = head;
    Node *prev = NULL;
    Node *xtmp;
    while (item != NULL)
    {
        Node *nxt = item->next;
        item->next = prev;
        prev = item;
        item = nxt;
    }
    tail = head;
    head = prev;
}

void list_reverse(int m, int n)
{
    Node *start = head;
    Node *item = head;
    Node *prev = head;
    int cnt;
    if (n <= m)
        return;
    //Determine start of the reversal
    for (cnt = 1; cnt < m; cnt++)
    {
        prev = item;
        item = item->next;
    }
    start = prev;
    cout << "Start value:" << start->value << endl;
    for (; cnt < n; cnt++)
    {
        Node *nxt = item->next;
        item->next = prev;
        prev = item;
        item = nxt;
    }
    start->next->next = item->next;
    start->next = item;
    item->next = prev;
    if (m == 1)
        head = item;
}

void list_reverse2(int m, int n)
{
    Node *item = head;
    Node *prev = NULL;
    Node *nxt = NULL;
    Node *start = NULL;

    int cnt;
    if (head == NULL)
        return;
    for (cnt = 1; cnt <= n; cnt++)
    {
        Node *nxt = item->next;
        if (cnt >= m)
        {
            if (start == NULL)
            {
                start = prev;
            }
            item->next = prev;
        }
        prev = item;
        item = nxt;
    }
    if (m == 1)
    {
        head = prev;
        tail = start;
        return;
    }
    if (item == NULL)
        tail = start->next;
    start->next->next = item;
    start->next = prev;
}

//Node *detect_cycle_simple(void)
//{
//    set<int> s1;
//    Node *item = head;
//    while (s1.find(item->value))
//}

void list_reverse_demo(void)
{
    cout << "Original list" << endl;
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    append(6);
    print_list();
    cout << "Reversed" << endl;
    list_reverse2(2, 3);
    print_list();
    //cout << endl << "Reversed list" << endl;

    //list_full_reverse();
    //print_list();
}
