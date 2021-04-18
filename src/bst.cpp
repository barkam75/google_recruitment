#include <cstddef>

typedef struct Node Node;

struct Node
{
    int value;
    Node *right;
    Node *left;
};

static Node *root = NULL;

bool bst_insert(int value)
{

    Node *element = new Node;
    Node *traverse = root;
    if (element == NULL)
    {
        //If element creation failed return false
        return false;
    }
    element->value = value;
    element->right = NULL;
    element->left = NULL;
    if (root == NULL)
    {
        root = element;
    }
    else
    {
        do
        {
            if (element->value > traverse->value)
            {
                //Go  right
                if (traverse->right == NULL)
                {
                    traverse->right == element;
                    return true;
                }
                else
                {
                    traverse = traverse->right;
                }
            }
            else
            {
                //Go left
                if (traverse->left == NULL)
                {
                    traverse->left == element;
                    return true;
                }
                else
                {
                    traverse = traverse->left;
                }
            }
        } while (traverse != NULL);
    }
    return true;
}