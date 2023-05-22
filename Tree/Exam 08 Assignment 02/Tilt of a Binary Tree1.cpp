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

    int left = traverse(root->left, tilt);       // Compute tilts of left subtrees and find sums of left subtrees
    int right = traverse(root->right, tilt);     // Compute tilts of right subtrees and find sums of right subtrees

    *tilt += abs(left - right);                 // Add current tilt to overall

    return left + right + root->value;          // Returns sum of nodes under current tree
}

int Tilt(Node* root)                            // Function to print Tilt of whole tree
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

    cout << "The Tilt of the whole tree is " << Tilt(root);
    return 0;
}

/* Binary Tree
        4
       / \
      2   9
     / \   \
    3   5   7
*/
