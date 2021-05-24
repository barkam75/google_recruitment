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

int BSTNode::treedepth()
{
    queue<pair<BSTNode *, int>> src_queue;
    pair<BSTNode *, int> item;
    int level = 0;
    src_queue.push(make_pair(this, level + 1));
    cout << endl;
    while (!src_queue.empty())
    {
        item = src_queue.front();
        src_queue.pop();
        cout << "Item: " << item.first->value << " is et level: " << item.second << endl;
        if (item.first->right != NULL)
            src_queue.push({item.first->right, item.second + 1});
        if (item.first->left != NULL)
            src_queue.push({item.first->left, item.second + 1});
    }
    return item.second;
}

int BSTNode::td_dfs(BSTNode *node, int count)
{
    int l, r;
    if (node == NULL)
        return count;
    cout << "Node: " << node->value << " at level: " << count << endl;
    cout << "Go left" << endl;
    l = td_dfs(node->left, count + 1);
    cout << "Go right" << endl;
    r = td_dfs(node->right, count + 1);
    return max(l, r);
}

int BSTNode::treedepthdfs()
{
    return td_dfs(this, 1);
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
    root->insert_i(7);
    root->insert_i(10);
    root->insert_i(11);
    cout << "5 nodes inserted" << endl;
    cout << "DFS Search" << endl;
    item = root->search_DFS(6);
    cout << "BFS search" << endl;
    item = root->search_BFS(4);
    cout << "Search completed" << endl;
    cout << "Tree depth:" << root->treedepth() << endl;
    cout << "Tree depth(DFS):" << root->treedepthdfs() << endl;
}
