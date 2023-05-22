// Iterative CPP program to convert a Binary Tree to its mirror
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

    queue<Node*> q;
    q.push(root);

    while(!q.empty())                // Do BFS. While doing BFS, keep swapping left and right children
    {
        Node* curr = q.front();      // pop top node from queue
        q.pop();

        swap(curr->left, curr->right);         // swap left child with right child

        if(curr->left != NULL)                 // push left and right children
        {
            q.push(curr->left);
        }

        if(curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void inOrder(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    inOrder(node->left);
    cout << node->value <<" ";
    inOrder(node->right);
}

int main()
{
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout<<"\nInorder traversal of the constructed tree is\n";
    inOrder(root);

    mirror(root);

    cout<<"\nInorder traversal of the mirror tree is\n";
    inOrder(root);

    return 0;
}
