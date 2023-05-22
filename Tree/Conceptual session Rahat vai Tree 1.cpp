#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTreeInOrder(Node *root);

int main()
{
    int a;
    cin>>a;

    Node *root = new Node(a);

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int x, y;
        cin>>x>>y;

        Node *n1 = NULL;
        Node *n2 = NULL;

        if(x != -1)
        {
            n1 = new Node(x);
        }

        if(y != -1)
        {
            n2 = new Node(y);
        }

        temp->left = n1;
        temp->right = n2;

        if(n1 != NULL)
        {
            q.push(n1);
        }

        if(n2 != NULL)
        {
            q.push(n2);
        }
    }

    printTreeInOrder(root);
    return 0;
}

void printTreeInOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    printTreeInOrder(root->left);
    cout<<root->val<<" ";
    printTreeInOrder(root->right);
}

/*

1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1      -1 -1

*/
