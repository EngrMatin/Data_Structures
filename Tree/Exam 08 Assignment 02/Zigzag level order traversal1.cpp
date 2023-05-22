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

void zizagTraversal(Node* root)
{
    if(root == NULL)                  // if null then return
    {
        return;
    }

    stack<Node*> currentLevel;           // declare two stacks
    stack<Node*> nextLevel;

    currentLevel.push(root);             // push the root

    bool leftToRight = true;
    while(!currentLevel.empty())         // check if stack is empty
    {
        Node* temp = currentLevel.top();    // pop out of stack
        currentLevel.pop();

        if(temp != NULL)                          // if not null
        {
            cout << temp->value << " ";           // print the data in it

            if(leftToRight)                    // store data according to current order.
            {
                if(temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }

                if(temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if(temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }

                if(temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout<<"ZigZag Order traversal of binary tree is\n";

    zizagTraversal(root);

    return 0;
}
