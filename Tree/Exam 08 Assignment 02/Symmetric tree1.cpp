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
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;

    // For two trees to be mirror images, the following
    // three conditions must be true
    // 1.) Their root node's key must be same
    // 2.) left subtree of left tree and right subtree of
    // right tree have to be mirror images
    // 3.) right subtree of left tree and left subtree of
    // right tree have to be mirror images
    if (root1 && root2 && root1->value == root2->value)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);

    // if none of above conditions is true then root1
    // and root2 are not mirror images
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
