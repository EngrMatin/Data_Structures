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

bool isUnivalTree(Node* root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left != NULL && root->value != root->left->value)
    {
        return false;
    }

    if (root->right != NULL && root->value != root->right->value)
    {
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(1);

    if(isUnivalTree(root))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
