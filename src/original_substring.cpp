#include <unordered_map>

#include "original_substring.h"

int find_largest(string s)
{
    int map[256];
    //  unordered_map<char, int> map;
    int p1 = 0;
    int p2 = 0;
    int cnt = 0;
    int max_len = 0;
    for (cnt = 0; cnt < 256; cnt++)
        map[cnt] = -1;
    while (p2 < s.length())
    {
        if (map[s[p2]] == -1)
        {
            map[s[p2]] = p2;
        }
        else
        {
            max_len = max_len < (p2 - p1) ? (p2 - p1) : max_len;
            while (p1 < map[s[p2]])
            {
                map[p1] = -1;
                p1++;
            }
        }
        p2++;
    }
    return max_len;
}
