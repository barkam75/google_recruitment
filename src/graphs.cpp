#include "graphs.h"

#include <iostream>
Graph::Graph(vector<pair<int, vector<int>>> &list) : adj_list(list)
{
}

bool Graph::search_bfs(int vertex, int value)
{
    int node;
    int item;
    search_queue.push(vertex);
    search_set.insert(vertex);
    while (!search_queue.empty())
    {
        item = search_queue.front();
        search_queue.pop();
        cout << "Traversing (BFS) through vertex: " << adj_list[item - 1].first << endl;
        if (item == value)
        {
            search_set.clear();
            while (!search_queue.empty())
                search_queue.pop();
            return true;
        }
        else
        {
            for (int cnt = 0; cnt < adj_list[item - 1].second.size(); cnt++)
            {
                node = adj_list[item - 1].second[cnt];
                auto search = search_set.find(node);
                if (search == search_set.end())
                {
                    search_set.insert(node);
                    search_queue.push(node);
                }
            }
        }
    }
    search_set.clear();
    return false;
}

bool Graph::search_dfs(int vertex, int value)
{
    cout << "Traversing (DFS) through vertex: " << adj_list[vertex - 1].first << endl;
    if (vertex == value)
    {
        return true;
    }
    else
    {
        //search_set.insert(vertex);
        for (int cnt = 0; cnt < adj_list[vertex - 1].second.size(); cnt++)
        {
            auto search = search_set.find(adj_list[vertex - 1].second[cnt]);
            if (search == search_set.end())
            {
                search_set.insert(adj_list[vertex - 1].second[cnt]);
                if (search_dfs(adj_list[vertex - 1].second[cnt], value))
                    return true;
            }
        }
    }
    return false;
}

int Graph::max_time(int vertex, int count)
{
    int mtime = count;
    cout << "Traversing (DFS) through vertex: " << vertex << endl;
    for (int cnt = 0; cnt < adj_list[vertex - 1].second.size(); cnt++)
    {
        auto search = search_set.find(adj_list[vertex - 1].second[cnt]);
        if (search == search_set.end())
        {
            search_set.insert(adj_list[vertex - 1].second[cnt]);
            mtime = max(max_time(adj_list[vertex - 1].second[cnt], count + adj_list[vertex - 1].first), mtime);
        }
    }
    return mtime;
}

void time_to_inform()
{
    const int n = 8;
    vector<pair<int, vector<int>>> company;
    vector<int> edges;
    int managers[n] = {3, 3, 5, 7, -1, 5, 5, 6};
    int delays[n] = {0, 0, 4, 0, 7, 3, 6, 0};
    //Create graph
    for (int i = 0; i < n; i++)
    {
        company.push_back(make_pair(delays[i], edges));
    }
    for (int i = 0; i < n; i++)
    {
        company[managers[i] - 1].second.push_back(i + 1);
    }
    /*  vector<pair<int, vector<int>>> company = {{0, {}},
                                              {0, {}},
                                              {4, {1, 2}},
                                              {0, {}},
                                              {7, {3, 6, 7}},
                                              {3, {8}},
                                              {6, {4}},
                                              {0, {}}}; */

    Graph test_gr(company);
    cout << "Time to inform:" << endl;
    test_gr.mark_vertex(5);
    int time_x = test_gr.max_time(5, 0);
    cout << "is " << time_x << " hours." << endl;
}

void graphs_demos()
{
    vector<pair<int, vector<int>>> adj_list = {{1, {2}}, {2, {1, 3}}, {3, {2, 4, 5}}, {4, {3, 6}}, {5, {3}}, {6, {4}}};
    Graph test_gr(adj_list);
    cout << "Graph demos here......" << endl;
    cout << "BFS ....." << endl;
    if (test_gr.search_bfs(3, 6))
    {
        cout << "Item found within a graph" << endl;
    }
    else
    {
        cout << "Nothing...." << endl;
    }
    cout << "DFS....." << endl;
    test_gr.mark_vertex(3);
    if (test_gr.search_dfs(3, 6))
    {
        cout << "Item found within a graph" << endl;
    }
    else
    {
        cout << "Nothing...." << endl;
    }

    time_to_inform();
}