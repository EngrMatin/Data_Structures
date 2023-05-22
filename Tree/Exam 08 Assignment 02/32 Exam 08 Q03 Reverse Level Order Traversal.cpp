#include <bits/stdc++.h>
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

void level_order_reverse(Node* root)
{
    stack<Node*> st;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();
        st.push(root);

        if(root->right)
        {
            q.push(root->right);
        }

        if(root->left)
        {
            q.push(root->left);
        }
    }

    while(!st.empty())
    {
        root = st.top();
        cout<<root->data<<" ";
        st.pop();
    }
}

int main()
{
    Node *root = new Node(3);

    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Reverse Level Order traversal of binary tree is \n";
    level_order_reverse(root);

    return 0;
}
