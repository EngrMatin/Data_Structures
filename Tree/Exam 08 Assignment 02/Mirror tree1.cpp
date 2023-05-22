//C++ program to convert a binary tree to its mirror
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

/* Change a tree so that the roles of the left and right pointers are swapped at every node.

So the tree...
     1
    / \
   2   3
  / \
 4   5

is changed to...
     1
    / \
   3   2
      / \
     5   4
*/

void mirror(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        mirror(root->left);                  // do the subtrees
        mirror(root->right);

        swap(root->left, root->right);       // swap the pointers in this root
    }
}

void inOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<< root->value <<" ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"\nInorder traversal of the constructed tree is"<<endl;
    inOrder(root);

    mirror(root);

    cout<<"\nInorder traversal of the mirror tree is"<<endl;
    inOrder(root);

    return 0;
}
