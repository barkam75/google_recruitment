#include <cstddef>

typedef struct Node Node;

struct Node
{
    int value;
    Node *right;
    Node *left;
};

static Node *root = NULL;

bool insert(int value)
{

    Node *element = new Node;
    Node *traverse = root;
    if (element == NULL)
    {
        //If element creation failed return false
        return false;
    }
    element->value = value;
    if (root == NULL)
    {
        root = element;
    }
    else
    {
        while (traverse)
            if (element->value > traverse->value)
            {
            }
    }
    return true;
}