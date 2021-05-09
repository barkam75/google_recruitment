#ifndef __DL_LISTS__
#define __DL_LISTS__
#include <iostream>
using namespace std;
class DLList
{
    int value;
    DLList *child;
    DLList *prev;
    DLList *next;
};

void dl_list_merge_demo(void);

#endif