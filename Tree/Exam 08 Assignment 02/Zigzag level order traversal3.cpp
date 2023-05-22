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

vector<int> zigZagTraversal(Node* root)
{
    if(root == NULL)
    {
        return {  };
    }

    vector<int> ans;
    queue<Node*> q;

    q.push(root);

    bool flag = false;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0 ; i < size ; i++)
        {
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->value);

            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        flag = !flag;
        if(flag == false)
        {
            reverse(level.begin(), level.end());
        }

        for(int i=0; i<level.size(); i++)
        {
          ans.push_back(level[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> v;        // vector to store the traversal order.

    Node* root = new Node(1);               // create tree

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "ZigZag Order traversal of binary tree is \n";

    v = zigZagTraversal(root);

    for (int i=0; i<v.size(); i++)
    {                                   // to print the order
        cout << v[i] << " ";
    }

    return 0;
}
