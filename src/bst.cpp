#include <cstddef>
#include <iostream>
#include <queue>
#include "bst.h"

using namespace std;

BSTNode::BSTNode()
{
    value = 0;
    left = NULL;
    right = NULL;
}

BSTNode *BSTNode::insert_r(int val)
{
    //Recursion used
    BSTNode *item = NULL;
    if (value > val)
    {
        if (right == NULL)
        {
            item = new BSTNode(val);
            right = item;
        }
        else
        {
            item = right->insert_r(val);
        }
    }
    else
    {
        if (left == NULL)
        {
            item = new BSTNode(val);
            left = item;
        }
        else
        {
            item = left->insert_r(val);
        }
    }

    return item;
}

BSTNode *BSTNode ::insert_i(int val)
{
    BSTNode *item = new BSTNode(val);
    BSTNode *node = this;
    while (node != NULL)
    {
        if (node->value > val)
        {
            //Go right
            if (node->right == NULL)
            {
                node->right = item;
                break;
            }
            else
            {
                node = node->right;
            }
        }
        else
        {
            // Go left
            if (node->left == NULL)
            {
                node->left = item;
                break;
            }
            else
            {
                node = node->left;
            }
        }
    }
    return item;
}

BSTNode *BSTNode::search_DFS(int val)
{
    BSTNode *item;
    cout << value << endl;
    if (value == val)
    {
        return this;
    }
    else
    {
        if (right != NULL)
        {
            item = right->search_DFS(val);
            if (item != NULL)
                return item;
        }
        if (left != NULL)
        {
            item = left->search_DFS(val);
            if (item != NULL)
                return item;
        }
    }
    return NULL;
}

BSTNode *BSTNode::search_BFS(int val)
{
    queue<BSTNode *> src_queue;
    BSTNode *item = NULL;
    src_queue.push(this);
    while (!src_queue.empty())
    {
        item = src_queue.front();
        cout << "BFS Search item:" << item->value << endl;
        src_queue.pop();
        if (item->value != val)
        {
            if (item->right != NULL)
                src_queue.push(item->right);
            if (item->left != NULL)
                src_queue.push(item->left);
        }
        else
        {
            return item;
        }
    }
    return NULL;
}

void bst_demo(void)
{
    BSTNode *root = new BSTNode(5);
    BSTNode *item = NULL;
    cout << "BST demo: Recursive insert" << endl;
    root->insert_i(3);
    root->insert_i(2);
    root->insert_i(4);
    root->insert_i(6);
    cout << "5 nodes inserted" << endl;
    cout << "DFS Search" << endl;
    item = root->search_DFS(6);
    cout << "BFS search" << endl;
    item = root->search_BFS(4);
    cout << "Search completed" << endl;
}
