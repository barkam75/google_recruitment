#include <cstddef>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
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
    if (value < val)
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
        if (node->value < val)
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
        if (left != NULL)
        {
            item = left->search_DFS(val);
            if (item != NULL)
                return item;
        }
        if (right != NULL)
        {
            item = right->search_DFS(val);
            if (item != NULL)
                return item;
        }
    }
    return NULL;
}

bool BSTNode::validate_bst(int minval, int maxval)
{
    bool lresult = true;
    bool rresult = true;
    cout << minval << " < (" << value << ") < " << maxval << endl;
    if ((value > minval) && (value < maxval))
    {
        if (left != NULL)
        {
            lresult = left->validate_bst(minval, value);
        }
        if (right != NULL)
        {
            rresult = right->validate_bst(value, maxval);
        }
        return (lresult && rresult);
    }
    else
    {
        return false;
    }
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
        if (item.first->left != NULL)
            src_queue.push({item.first->left, item.second + 1});
        if (item.first->right != NULL)
            src_queue.push({item.first->right, item.second + 1});
    }
    return item.second;
}

int BSTNode::td_dfs(BSTNode *node, int count)
{
    int l, r;
    if (node == NULL)
        return count;
    return max(td_dfs(node->left, count + 1), td_dfs(node->right, count + 1));
}

int BSTNode::treedepthdfs()
{
    return td_dfs(this, 1) - 1;
}

void BSTNode::level_order()
{
    string s;
    queue<pair<BSTNode *, int>> src_queue;
    pair<BSTNode *, int> item;
    int level = 0;
    s = "[[";
    src_queue.push({this, level + 1});
    while (!src_queue.empty())
    {
        item = src_queue.front();
        src_queue.pop();
        if (level < item.second)
        {
            s += "],[" + to_string(item.first->value);
            level++;
        }
        else
        {
            s += "," + to_string(item.first->value) + ",";
        }
        if (item.first->left != NULL)
            src_queue.push({item.first->left, item.second + 1});
        if (item.first->right != NULL)
            src_queue.push({item.first->right, item.second + 1});
    }
    s += "]";
    cout << s << endl;
}

void BSTNode::level_order2()
{
    queue<BSTNode *> src_queue;
    BSTNode *item;
    vector<int> mid_arr;
    string s = "[";
    string s2 = "";
    int count = 0;
    int level_size = 1;
    src_queue.push(this);
    while (!src_queue.empty())
    {
        for (int i = 0; i < level_size; i++)
        {
            item = src_queue.front();
            src_queue.pop();
            mid_arr.push_back(item->value);
            if (item->left != NULL)
            {
                src_queue.push(item->left);
                count++;
            };
            if (item->right != NULL)
            {
                src_queue.push(item->right);
                count++;
            };
        }
        s2 = "[";
        for (auto &num : mid_arr)
        {
            s2 += to_string(num) + ",";
        }
        mid_arr.clear();
        s2 += "]";
        cout << s2 << endl;
        level_size = count;
        count = 0;
        s += "," + s2;
    }
    cout << s << endl;
}

void BSTNode::right_side()
{
    queue<BSTNode *> src_queue;
    BSTNode *item;
    vector<int> mid_arr;
    string s = "[";
    string s2 = "";
    int count = 0;
    int level_size = 1;
    cout << "Right side of the tree" << endl;
    src_queue.push(this);
    while (!src_queue.empty())
    {
        for (int i = 0; i < level_size; i++)
        {
            item = src_queue.front();
            src_queue.pop();
            if (i == (level_size - 1))
                mid_arr.push_back(item->value);
            if (item->left != NULL)
            {
                src_queue.push(item->left);
                count++;
            }
            if (item->right != NULL)
            {
                src_queue.push(item->right);
                count++;
            }
        }
        level_size = count;
        count = 0;
    }
    for (auto &num : mid_arr)
    {
        cout << to_string(num) + ",";
    }
    cout << endl;
}

void BSTNode::rs_dfs(BSTNode *node, int level, vector<int> &table)
{
    if (node != NULL)
    {
        if (level > table.size())
        {
            table.push_back(node->value);
        }
        if (node->right != NULL)
        {
            rs_dfs(node->right, level + 1, table);
        }
        if (node->left != NULL)
        {
            rs_dfs(node->left, level + 1, table);
        }
    }
    return;
}

void BSTNode::right_side_dfs()
{
    vector<int> rside;
    rs_dfs(this, 1, rside);
    cout << "Right side of the tree DFS" << endl;
    for (auto num : rside)
    {
        cout << num << ",";
    }
    cout << endl;
}

bool BSTNode::bst_traverse(int level, int num)
{
    BSTNode *item = this;
    int mask = (1 << level - 1);
    while (level != 0)
    {
        if ((mask & num) != 0)
        {
            item = item->right;
        }
        else
        {
            item = item->left;
        }
        if (item == NULL)
            return false;
        mask = mask >> 1;
        level--;
    }
    return true;
}

int BSTNode::complete_number()
{
    BSTNode *item = this;
    int level = 0;
    int r = 0;
    int l = 0;
    int mid;
    while (item->left != NULL)
    {
        item = item->left;
        level++;
    }
    cout << "Tree level: " << level << endl;
    r = (1 << level) - 1;
    while (l != r)
    {

        //mid = (l + r) / 2;
        mid = 1 + (((l + r) - 1) / 2);
        cout << "MID:" << mid << endl;
        if (bst_traverse(level, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "LValue:" << l << endl;
    return ((2 << (level - 1)) - 1) + l + 1;
}

void tree_size_demo()
{
    BSTNode *root = new BSTNode(12);
    BSTNode *test;
    cout << "Complete tree size demo" << endl;
    root->insert_r(8);
    //  test = root->insert_r(10);
    root->insert_r(5);
    //test->set_left(new BSTNode(3));
    root->insert_r(3);
    root->insert_r(6);
    root->insert_r(10);
    root->insert_r(9);
    root->insert_r(11);
    root->insert_r(17);
    root->insert_r(19);
    root->insert_r(15);
    root->insert_r(14);
    root->insert_r(16);
    root->insert_r(18);
    root->insert_r(20);
    cout << "Number elements in the complete tree: xxx-" << root->complete_number() << endl;
    if (root->validate_bst(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
    {
        cout << "Valid BST tree" << endl;
    }
    else
    {
        cout << "Invalid BST tree" << endl;
    }
}

void bst_demo(void)
{
    BSTNode *root = new BSTNode(5);
    BSTNode *item = NULL;
    cout << "BST demo: Recursive insert" << endl;
    root->insert_r(3);
    root->insert_r(2);
    root->insert_r(4);
    root->insert_r(6);
    root->insert_r(7);
    root->insert_r(1);
    root->insert_r(0);
    //root->insert_r(10);
    //root->insert_r(11);
    cout << "5 nodes inserted" << endl;
    cout << "DFS Search" << endl;
    item = root->search_DFS(6);
    cout << "BFS search" << endl;
    item = root->search_BFS(4);
    cout << "Search completed" << endl;
    cout << "Tree depth:" << root->treedepth() << endl;
    cout << "Tree depth(DFS):" << root->treedepthdfs() << endl;
    cout << "Level order demo" << endl;
    root->level_order2();
    root->right_side();
    root->right_side_dfs();

    tree_size_demo();
}
