
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void level_order(Node *root);

int main()
{
    Node *root = new Node(3);

    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    level_order(root);

    return 0;
}

void level_order(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    cout<<"Level Order Traversal: ";
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp != NULL)
        {
            cout<<temp->data<<" ";

            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        else
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
    cout<<endl;
}
