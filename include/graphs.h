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
    unordered_set<unsigned long> search_set;

public:
    Graph(vector<pair<int, vector<int>>> &list);
    search_bfs(int value);
};

void graphs_demos();
#endif