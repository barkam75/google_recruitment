#include <iostream>
#include <string>
using namespace std;
#define DEL_CHAR '#'

int get_next_char(string s, int start)
{
  int del_cnt = 0;
  int cnt = start - 1;
  while (cnt > 0)
  {
    if (s[cnt] == DEL_CHAR)
    {
      del_cnt++;
    }
    else
    {
      if (del_cnt > 0)
      {
        del_cnt--;
      }
      else
      {
        return cnt;
      }
    }
    cnt--;
  }
  return cnt;
}

bool str_enc_cmp(string s1, string s2)
{
  int cnt = 0;
  int p1 = s1.length();
  int p2 = s2.length();

  while ((p1 > 0) && (p2 >= 0))
  {
    p1 = get_next_char(s1, p1);
    p2 = get_next_char(s2, p2);
    if ((p1 >= 0) && (p2 >= 0))
      if (s1[p1] != s2[p2])
        return false;
  }
  return true;
}
