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

void averageOfLevels(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        double sum = 0.00;
        int count = 0;
        queue<Node*> tempQ;

        while (!q.empty())
        {
            Node* chkNode = q.front();
            q.pop();
            sum += chkNode->value;
            count++;

            if (chkNode->left != NULL)
            {
                tempQ.push(chkNode->left);
            }

            if (chkNode->right != NULL)
            {
                tempQ.push(chkNode->right);
            }
        }

        q = tempQ;
        cout<< sum/count <<" ";
    }
}

int main()
{
    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    averageOfLevels(root);

    return 0;
}

/* Binary Tree
        4
       / \
      2   9
     / \   \
    3   5   7
*/

