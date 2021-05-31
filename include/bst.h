#ifndef __BST_ROUTINES__
#define __BST_ROUTINES__
#include <vector>

bool bst_insert(int v);

class BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;
    int td_dfs(BSTNode *node, int count);
    void rs_dfs(BSTNode *node, int level, std::vector<int> &table);

public:
    BSTNode();
    BSTNode(int v) : BSTNode() { value = v; }
    BSTNode *insert_r(int v);
    BSTNode *insert_i(int v);
    BSTNode *search_DFS(int v);
    BSTNode *search_BFS(int v);
    int treedepth();
    int treedepthdfs();
    void level_order();
    void level_order2();
    void right_side();
    void right_side_dfs();
    int complete_number();
    bool bst_traverse(int level, int leafnum);
};

void bst_demo(void);
#endif