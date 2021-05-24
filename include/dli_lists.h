#ifndef __DL_LISTS__
#define __DL_LISTS__
#include <iostream>
using namespace std;
class DList
{
public:
    int value;
    DList *next;
    DList *prev;
    DList *child;
    DList();
};

void dl_list_merge_demo(void);

#endif