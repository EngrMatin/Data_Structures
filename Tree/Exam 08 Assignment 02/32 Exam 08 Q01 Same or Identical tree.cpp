//https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(Node* a, Node* b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }

    if (a != NULL && b != NULL)
    {
        if(a->value == b->value &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right))
            {
                return true;
            }
    }

    return false;
}

int main()
{
    Node *root1 = new Node(1);
    Node *root2 = new Node(1);

    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if(identicalTrees(root1, root2))
    {
        cout << "Both tree are identical.";
    }
    else
    {
        cout << "Trees are not identical.";
    }

    return 0;
}
