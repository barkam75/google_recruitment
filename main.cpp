//data structures_demo
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "twosum.h"
#include "maxcontainer.h"
#include "rainwater.h"
#include "hashstr_cmp.h"
#include "original_substring.h"
#include "palindromes.h"
#include "lists.h"
#include "dli_lists.h"
#include "queue_on_stacks.h"
#include "bst.h"
#include "maxkth.h"
#include "heaps.h"
#include "arrays2d.h"

using namespace std;

void check_brackets(string &s)
{
    int p1 = 0;
    int p;
    while (s[p1] != 0x00)
    {
        if (s[p1] == '(')
        {
            push(p1);
            p1++;
        }
        else if (s[p1] == ')')
        {
            if (pop(&p))
            {
                p1++;
            }
            else
            {
                s.erase(p1, 1);
            }
        }
        else
        {
            p1++;
        }
    }
    while (pop(&p))
    {
        cout << "Char to erase: " << p << endl;
        s.erase(p, 1);
    }
}

void check_bracket_demo(void)
{
    string s = "a))))((bc(d)())(";
    cout << "Input string: " << s << endl;
    check_brackets(s);
    cout << "Output string: " << s << endl;
}

void queue_on_stack_demo(void)
{
    Queue q;
    int v;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << "Queue on stacks demo" << endl;
    cout << "Queue peek " << (q.peek()->value) << endl;
    cout << "Dequeue elements" << endl;
    while (q.dequeue(v))
    {
        cout << "Queue element: " << v << endl;
    }
    cout << "Empty test" << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.empty();
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    while (q.dequeue(v))
    {
        cout << "(E)Queue element: " << v << endl;
    }
}

void stack_demo(void)
{
    int v;
    cout << "Stack demo" << endl;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    cout << "Pushed 6 items" << endl;
    while (pop(&v))
        cout << "Value:" << v << endl;
}
void queue_demo(void)
{
    int v;
    cout << "FIFO demo" << endl;
    enqueue(1);
    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(9);
    cout << getSize() << endl;
    //reverse(3);
    while (!isEmpty())
    {
        dequeue(&v);
        cout << "Dequeued element:" << v << endl;
    }
    cout << getSize() << endl;
}

void twosum_demo(void)
{
    int numbers[] = {1, 2, 8, 6, 7, 9, 11};
    int p1,
        p2;
    if (twoSum_basic(numbers, 7, 11, p1, p2))
    {
        cout << "basic" << endl;
        cout << "P1:" << p1 << " P2: " << p2 << endl;
    }

    if (twoSum_optimal(numbers, 7, 11, p1, p2))
    {
        cout << "optimal" << endl;
        cout << "P1:" << p1 << " P2: " << p2 << endl;
    }
}

void maxcontainer_demo(void)
{
    int numbers[] = {7, 1, 2, 3, 9};
    int p1, p2, area;
    maxcontainer_brute(numbers, 5, p1, p2, area);
    cout << "Max area demo (brute)" << endl;
    cout << "Max area: " << area << " by points at:(" << p1 << "," << p2 << ")" << endl;

    maxcontainer_optimal(numbers, 5, p1, p2, area);
    cout << "Max area demo (optimal)" << endl;
    cout << "Max area: " << area << " by points at:(" << p1 << "," << p2 << ")" << endl;
    cout << "Array size:" << sizeof(numbers) / sizeof(numbers[0]) << endl;
}

void rainwater_demo()
{
    //int numbers[] = {0, 3, 2, 3, 0, 3, 2, 1, 2, 9, 4, 0, 4, 3, 2, 2, 1, 3, 0};
    // int numbers[] = {5, 3, 4, 5, 0, 6, 5, 4, 3, 2, 3, 4, 8};
    int numbers[] = {0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2};
    cout << "Trapped rainwater demo" << endl;
    cout << "Trapped water(brute):" << trapped_rainwater_brute(numbers, 11) << endl;
    cout << "Trapped water(optim):" << trapped_rainwater(numbers, 11) << endl;
    cout << "Trapped water(optim2):" << trapped_rainwater_2_optim(numbers, 11) << endl;
}

void hashstr_cmp_demo(void)
{
    string s1 = "adab##c";
    string s2 = "adc";
    cout << "Str cmp demo!\n";
    cout << "Next char ptr:" << get_next_char(s1, s1.length() - 1) << endl;
    cout << "Str cmp result:" << str_enc_cmp(s1, s2) << endl;
}

void original_substring_demo(void)
{
    // string s = "abcdcbadfgzhj";
    //string s = "abc0abc0abc0abc0ab0abc0";
    string s = "aaaaaaaaa";
    cout << "Largest substring:" << find_largest(s) << endl;
}

int main(void)
{
    array_dfs_demo();
    //heaps_demo();
    // sort_demo();
    // bst_demo();
    //queue_on_stack_demo();
    //check_bracket_demo();
    //dl_list_merge_demo();
    //list_reverse_demo();
    //palindromes_demo();
    //original_substring_demo();
    //hashstr_cmp_demo();
    //rainwater_demo();
    //maxcontainer_demo();
    //twosum_demo();
    // stack_demo();
    //queue_demo();
    return 0;
}