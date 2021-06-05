#include "graphs.h"

#include <iostream>
Graph::Graph(vector<pair<int, vector<int>>> &list) : adj_list(list)
{
}

void graphs_demos()
{
    vector<pair<int, vector<int>>> adj_list = {{0, {1}}, {1, {0, 2}}, {2, {1}}};
    Graph test_gr(adj_list);
    cout << "Graph demos here......" << endl;
}