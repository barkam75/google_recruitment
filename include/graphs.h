#ifndef __GRAPHS_DEMO__
#define __GRAPHS_DEMO__
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

class Graph
{
private:
    vector<pair<int, vector<int>>> &adj_list;
    queue<int> search_queue;
    unordered_set<int> search_set;

public:
    Graph(vector<pair<int, vector<int>>> &list);
    void flush(void) { search_set.clear(); };
    bool search_bfs(int vertex, int value);
    bool search_dfs(int vertex, int value);
    void mark_vertex(int vertex) { search_set.insert(vertex); };
    int max_time(int vertex, int count);
};

void graphs_demos();
#endif