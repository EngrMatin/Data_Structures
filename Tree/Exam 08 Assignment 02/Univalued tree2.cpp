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

bool isUnivalTree(Node* root)
{
    if (root == NULL)
    {
        return true;
    }
                                      // Store nodes at each level of the tree
    queue<Node*> q;

    q.push(root);                     // Insert root node

    int rootVal = root->value;        // Stores value of root node

    while (!q.empty())                 // Traverse the tree using BFS
    {
        Node* currRoot = q.front();        // Stores front element of the queue

        if (currRoot->value != rootVal)   // If value of  traversed node not equal to value of root node
        {
            return false;
        }

        if (currRoot->left != NULL)         // If left subtree is not NULL
        {
            q.push(currRoot->left);        // Insert left subtree
        }

        if (currRoot->right != NULL)        // If right subtree is not NULL
        {
            q.push(currRoot->right);      // Insert right subtree
        }

        q.pop();                           // Remove front element of the queue
    }

    return true;
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

/*
                1
              /   \
             1     1
           /  \     \
          1    1     1
*/
