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

bool isCousinNode(Node* root, int x, int y);

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    if (isCousinNode(root, 7, 4))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

bool isCousinNode(Node* root, int x, int y)
{
    queue<Node *> q;
    q.push(root);

    while(q.size())
    {
        int n = q.size();
        bool isX = false, isY = false;

        for(int i=0; i<n; i++)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->value == x)
            {
                isX = true;
            }
            if(temp->value == y)
            {
                isY = true;
            }

            if(temp->left && temp->right)
            {
                if((temp->left->value == x && temp->right->value == y) ||
                   (temp->left->value == y && temp->right->value == x))
                {
                    return false;
                }
            }

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        if(isX && isY)
        {
            return true;
        }
    }

    return false;
}

