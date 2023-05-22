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

bool rootEqualToSumOfChildren(Node* &root);

int main()
{
    Node *root = new Node(10);

    root->left = new Node(4);
    root->right = new Node(3);


    if (rootEqualToSumOfChildren(root))
        cout << "True";
    else
        cout << "False";
    return 0;
}

bool rootEqualToSumOfChildren(Node* &root)
{
    return root->value == root->left->value + root->right->value;
}
