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

int findSecondMinimumValue(Node* root)
{
    if (root == NULL)                           // When the root is null
    {
        return -1;
    }

    if (root->left == NULL && root->right == NULL)        // Base Condition: When we reach the Leaf node, we have to return -1
    {
        return -1;
    }

    auto left = root->left->value;         // Storing the Node value of the left child of the Node
    auto right = root->right->value;       // Storing the Node value of the right child of the Node

    // Call the function recursively to the left sub-part of the tree if the value of the node value matches with its left child node value
    if (root->value == root->left->value)
    {
        left = findSecondMinimumValue(root->left);
    }

    // Call the function recursively to the right sub-part of the tree if the value of the node value matches with its right child node value
    if (root->value == root->right->value)
    {
        right = findSecondMinimumValue(root->right);
    }

    // In case if both the left and right child value is not equal to -1 then in that case return the minimum of them to the its parent
    if (left != -1 && right != -1)
    {
        return min(left, right);
    }

    // In case if the left child's value is not equal to -1 BUT its right child's value is equal to -1 then in that case send the left child value to its parent node.
    else if (left != -1)
    {
        return left;
    }

    // In case if the right child's value is not equal to -1 BUT its left child's value is equal to -1 then in that case send the right child value to its parent node.
    else
    {
        return right;
    }
}

int main()
{
    Node* root = new Node(2);          // Creating the root node

    root->left = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int SecondMinimumValue = findSecondMinimumValue(root);
    cout << SecondMinimumValue << endl;
    return 0;
}

/*             2
              / \
             2   5
                / \
               5   7
*/
