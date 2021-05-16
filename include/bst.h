#ifndef __BST_ROUTINES__
#define __BST_ROUTINES__
bool bst_insert(int v);

class BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode();
    BSTNode(int v) : BSTNode() { value = v; }
    BSTNode *insert_r(int v);
    BSTNode *insert_i(int v);
    BSTNode *search_DFS(int v);
    BSTNode *search_BFS(int v);
};

void bst_demo(void);
#endif