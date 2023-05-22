// C++ program to check if a given Binary Tree is symmetric or not
#include <bits/stdc++.h>
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

bool isMirror(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1 != NULL && root2 != NULL && root1->value == root2->value)
    {
        if(isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left))
        {
            return true;
        }
    }

    return false;
}

bool isSymmetric(Node* root)
{
    return isMirror(root, root);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
        cout << "This tree is a symmetric tree.";
    else
        cout << "This tree is not a symmetric tree.";
    return 0;
}
