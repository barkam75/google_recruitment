#include "dli_lists.h"

DLList *head = NULL;
DLList *tail = NULL;

DLList *append(DLList *&root, int value)
{
    DLList *item = new DLList;
    if (item != NULL)
    {
        item->value = value;
        item->next = root;
        if (root = NULL)
        {
            root = item;
        }
        else
        {
            while (item)
        }
    }
    return item;
}

void dl_list_merge_demo(void)
{
}
