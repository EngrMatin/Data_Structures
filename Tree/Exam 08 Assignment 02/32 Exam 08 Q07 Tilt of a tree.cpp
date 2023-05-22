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

int traverse(Node *root, int *tilt)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);

    *tilt += abs(left - right);

    return left + right + root->value;
}

int findTilt(Node* root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

int main()
{

    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "The Tilt of the whole tree is " << findTilt(root);
    return 0;
}

/* Binary Tree
        4
       / \
      2   9
     / \   \
    3   5   7
*/
