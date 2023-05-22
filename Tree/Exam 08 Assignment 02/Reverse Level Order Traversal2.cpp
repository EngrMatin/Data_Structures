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

void reverseLevelOrder(Node* root)
{
    stack <Node *> st;
    queue <Node *> q;
    q.push(root);

    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (!q.empty())
    {
        /* Dequeue node and make it root */
        root = q.front();
        q.pop();
        st.push(root);

        /* Enqueue right child */
        if (root->right)
            q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

        /* Enqueue left child */
        if (root->left)
            q.push(root->left);
    }

    // Now pop all items from stack one by one and print them
    while (!st.empty())
    {
        root = st.top();
        cout << root->data << " ";
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
    reverseLevelOrder(root);

    return 0;
}
