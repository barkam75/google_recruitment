#ifndef __PALINDROMES__

#define __PALINDROMES__
#include <string>

using namespace std;

void palindromes_demo(void);
bool check_palindrome(string s, int &mismatch_l, int &mismatch_r);
bool check_almostpalindrome(string s);
#endif