#include "arrays2d.h"

#include <iostream>
Array2D::Array2D(vector<vector<int>> &ptr) : data_ptr(ptr)
{
    data_ptr = ptr;
    data_height = data_ptr.size();
    if (data_height > 0)
    {
        data_width = data_ptr[1].size();
    }
    else
    {
        data_width = -1;
    }
}

bool Array2D::check_encode(int x, int y, bool mark)
{
    //Checks if element was already searched
    unsigned long tmp = (y << 16) + x;
    auto search = search_set.find(tmp);
    if (search != search_set.end())
    {
        //If yes return false
        return true;
    }
    //If not mark it as chequed and return false
    if (mark)
        search_set.insert(tmp);
    return false;
}

bool Array2D::is_valid(int x, int y)
{ //Check if specified coordinates are within array boundaries
    if ((x < 0) || (x >= data_width))
        return false;
    if ((y < 0) || (y >= data_height))
        return false;
    return true;
}
bool Array2D::search_dfs(int val, int &x, int &y)
{
    cout << " 2D array dfs search" << endl;
    search_set.clear();
    bool result = dfs(0, 0, val);
    x = result ? src_result_x : -1;
    y = result ? src_result_y : -1;
    search_set.clear();
    return result;
}

bool Array2D::dfs(int x, int y, int value)
{
    //Check if coordinates are right
    if (!is_valid(x, y))
        return false;
    //Check if element at current coordinates were already checked
    if (check_encode(x, y, true))
        return false;
    cout << "Data(" << x << "," << y << "):" << data_ptr[y][x] << endl;
    if (data_ptr[y][x] == value)
    {
        src_result_x = x;
        src_result_y = y;

        return true;
    }
    if (dfs(x, y - 1, value)) //Go up
        return true;
    if (dfs(x + 1, y, value)) //Go right
        return true;
    if (dfs(x, y + 1, value)) //Go down
        return true;
    if (dfs(x - 1, y, value)) //Go left
        return true;
    return false;
}

int Array2D::bfs_enqueue(int x, int y)
{
    if (is_valid(x, y))
    {
        if (!check_encode(x, y, true))
        {
            pair<int, int> item = {x, y};
            search_queue.push(item);
            return 1;
        }
    }
    return 0;
}

bool Array2D::search_bfs(int value, int &x, int &y)
{
    pair<int, int> item = {x, y};
    cout << "2D array BFS search" << endl;
    bfs_enqueue(x, y);
    while (!search_queue.empty())
    {
        item = search_queue.front();
        search_queue.pop();
        x = item.first;
        y = item.second;
        cout << "Data(" << x << "," << y << "):" << data_ptr[y][x] << endl;
        if (data_ptr[y][x] == value)
        {
            flush_queue();
            return true;
        }
        bfs_enqueue(x, y - 1); //Go up
        bfs_enqueue(x + 1, y); //Go right
        bfs_enqueue(x, y + 1); //Go down
        bfs_enqueue(x - 1, y); //Go left
    }
    return false;
}

int Array2D::isolate_island(int x, int y)
{
    int rings = 0;
    int n;
    int item_count = 1;
    int count = 0;
    pair<int, int> item = {x, y};
    cout << "Isolating island ..." << endl;
    while (!search_queue.empty())
    {
        cout << "Ring...." << endl;
        for (n = 0; n < item_count; n++)
        {
            item = search_queue.front();
            search_queue.pop();
            x = item.first;
            y = item.second;
            cout << "Data(" << x << "," << y << "):" << data_ptr[y][x] << endl;
            if (data_ptr[y][x] == 1)
            {
                count += bfs_enqueue(x, y - 1); //Go up
                count += bfs_enqueue(x + 1, y); //Go right
                count += bfs_enqueue(x, y + 1); //Go down
                count += bfs_enqueue(x - 1, y); //Go left
            }
        }
        item_count = count;
        count = 0;
        rings++;
    }
    cout << "Searched rings: " << rings << endl;
    return rings;
}

int Array2D::island_search()
{
    int islands = 0;
    int x;
    int y;
    for (y = 0; y < data_height; y++)
        for (x = 0; x < data_width; x++)
        {
            if (!check_encode(x, y, false))
            {
                //New element
                if (data_ptr[y][x] == 1)
                {
                    islands++;
                    //New island found
                    bfs_enqueue(x, y);
                    isolate_island(x, y);
                }
            }
        }
    return islands;
}

int Array2D::rotten_oranges()
{
    int x;
    int y;
    int time = 0;
    for (y = 0; y < data_height; y++)
    {
        for (x = 0; x < data_width; x++)
        {
            if (!check_encode(x, y, false))
            {
                if (data_ptr[y][x] == 2)
                {
                    //Roting orange found
                    data_ptr[y][x] = 1;
                    bfs_enqueue(x, y);
                    time = max(time, isolate_island(x, y));
                }
            }
        }
    }
    return time - 1;
}

void array_dfs_demo()
{
    int x, y;
    vector<vector<int>> numbers = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    Array2D *search_array = new Array2D(numbers);
    if (search_array->search_dfs(14, x, y))
    {
        cout << "Item found at: " << x << "," << y << endl;
    }
    x = 2;
    y = 2;
    if (search_array->search_bfs(70, x, y))
    {
        cout << "Item found at: " << x << "," << y << endl;
    }
    else
    {
        cout << "Upps... Nobody there?" << endl;
    }
    //vector<vector<int>> sea = {{0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 0, 1, 0, 0}, {1, 0, 1, 0, 0}};
    vector<vector<int>> sea = {{1, 1, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 0, 0, 1, 1}};
    vector<vector<int>> oranges = {{2, 1, 1, 0, 0}, {1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 1, 0, 0, 1}};
    Array2D *islands = new Array2D(sea);
    cout << "Finding islands" << endl;
    x = islands->island_search();
    cout << "Islands found: " << x << endl;
    Array2D *rot = new Array2D(oranges);
    cout << "Roting oranges" << endl;
    x = rot->rotten_oranges();
    cout << "Time to rot all oranges: " << x << endl;
}