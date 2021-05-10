#include "dli_lists.h"

static DList *head = NULL;
static DList *tail = NULL;

DList::DList()
{
    next = NULL;
    prev = NULL;
    child = NULL;
    value = 0;
}

DList *append(DList *&root, int value)
{
    DList *item;
    item = new DList;
    if (item != NULL)
    {
        item->value = value;
        if (root == NULL)
        {
            root = item;
        }
        else
        {
            //Do the traversal
            DList *node = root;
            while (node->next != NULL)
            {
                node = node->next;
            }
            item->prev = node;
            node->next = item;
        }
    }
    return item;
}

void list_merge(void)
{
    DList *item = head;
    while (item != NULL)
    {
        if (item->child != NULL)
        {
            DList *rJoint = item->next;
            item->next = item->child;
            DList *child_item = item->child;
            while (child_item->next != NULL)
            {
                child_item = child_item->next;
            }
            child_item->next = rJoint;
            rJoint->prev = child_item;
            item->child = NULL;
        }
        item = item->next;
    }
}

void list_merge_recursive(DList *&root)
{
    DList *item = root;
    while (item != NULL)
    {
        if (item->child != NULL)
        {
        }
        item = item->next;
    }
}

void show_list(DList *root)
{
    DList *item = root;
    while (item != NULL)
    {
        cout << "Item:" << item->value << endl;
        item = item->next;
    }
}

void dl_list_merge_demo(void)
{
    DList *parent;
    std::cout << "Dual link list merge!\n";
    append(head, 1);
    parent = append(head, 2);
    append(head, 3);
    append(head, 4);
    show_list(head);
    cout << "Show children" << endl;
    append(parent->child, 10);
    append(parent->child, 11);
    append(parent->child, 12);
    append(parent->child, 13);
    show_list(parent->child);
    cout << "Merged list" << endl;
    list_merge();
    show_list(head);
}
