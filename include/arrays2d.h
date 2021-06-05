#ifndef __ARRAYS_2D__
#define __ARRAYS_2D__
#include <utility>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Array2D
{
private:
    vector<vector<int>> &data_ptr;
    int src_result_x;
    int src_result_y;
    int data_width;
    int data_height;
    unordered_set<unsigned long> search_set;
    queue<pair<int, int>> search_queue;
    bool dfs(int x, int y, int value);
    int bfs_enqueue(int x, int y);
    bool check_encode(int x, int y, bool mark);
    bool is_valid(int x, int y);
    void flush_queue(void)
    {
        while (!search_queue.empty())
            search_queue.pop();
    };
    int isolate_island(int x, int y);

public:
    Array2D(vector<vector<int>> &ptr);
    bool search_dfs(int value, int &x, int &y);
    bool search_bfs(int value, int &x, int &y);
    int rotten_oranges();
    int island_search();
};

void array_dfs_demo();
#endif