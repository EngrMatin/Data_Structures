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

vector<int> v;                        // Initialize a vector

void inorder_traversal(Node* root)       // Traversing the tree by using inorder traversal
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        v.push_back(root->value);
        inorder_traversal(root->right);
    }
}

int second_minimum(Node* root)
{
    inorder_traversal(root);

    sort(v.begin(), v.end());

    for(int i=0; i<v.size()-1; i++)
    {
        if(v[i] != v[i+1])
        {
            return v[i+1];
        }
    }
    return -1;
}

int main()
{
    Node* root = new Node(2);

    root->left = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int secondMinimumValue = second_minimum(root);
    cout << secondMinimumValue << endl;

    return 0;
}

//         2
//        / \
//       2   5
//          / \
//         5   7
