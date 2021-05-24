#include <iostream>
#include "palindromes.h"

void palindromes_demo(void)
{
    string s = "abcdefdba";
    int m_l;
    int m_r;
    cout << "Text:" << s;
    if (check_palindrome(s, m_l, m_r))
    {
        cout << " is a palindrome";
    }
    else
    {
        cout << " is not a palindrome. Mismatching characters at index:" << m_l << " and " << m_r << endl;
    }
    if (check_almostpalindrome(s))
    {
        cout << " but it is an almost palindrome" << endl;
    }
    else
    {
        cout << " and it is not an almost palindrome" << endl;
    }
}

bool check_palindrome(string s, int &mismatch_l, int &mismatch_r)
{
    int diff = s.length() % 2;
    int left = 0;
    int right = s.length();
    while ((right - left) != diff)
    {
        if (s[left] != s[right - 1])
        {
            mismatch_l = left;
            mismatch_r = right - 1;
            return false;
        }
        left++;
        right--;
    }
    mismatch_l = 0;
    mismatch_r = 0;
    return true;
}

bool check_almostpalindrome(string s)
{
    int m_l, m_r;
    char c;
    if (check_palindrome(s, m_l, m_r))
    {
        return true;
    }
    else
    {
        int l, r;
        c = s[m_l];
        s.erase(m_l, 1);
        if (check_palindrome(s, l, r))
        {
            return true;
        }
        else
        {
            s.insert(s.begin() + m_l, 1, c);
            s.erase(m_r, 1);
            if (check_palindrome(s, l, r))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
