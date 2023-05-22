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

vector<int> zigZagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->value);
    Node* temp;

    int l = 1;               // set initial level as 1, because root is already been taken care of.

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
                                           // popping mechanism
            if (l % 2 == 0)
            {
                temp = q.back();
                q.pop_back();
            }
            else
            {
                temp = q.front();
                q.pop_front();
            }

                                            // pushing mechanism
            if (l % 2 != 0)
            {
                if (temp->right)
                {
                    q.push_back(temp->right);
                    v.push_back(temp->right->value);
                }

                if (temp->left)
                {
                    q.push_back(temp->left);
                    v.push_back(temp->left->value);
                }
            }
            else if (l % 2 == 0)
            {
                if (temp->left)
                {
                    q.push_front(temp->left);
                    v.push_back(temp->left->value);
                }

                if (temp->right)
                {
                    q.push_front(temp->right);
                    v.push_back(temp->right->value);
                }
            }
        }
        l++;              // level plus one
    }
    return v;
}

int main()
{
    vector<int> v;                // vector to store the traversal order.

    Node* root = new Node(1);         // create tree

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "ZigZag Order traversal of binary tree is \n";

    v = zigZagTraversal(root);

    for (int i = 0; i < v.size(); i++)
    {                                // to print the order
        cout << v[i] << " ";
    }

    return 0;
}
