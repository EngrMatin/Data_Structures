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

//void zizagTraversal(Node* root)
void zigzag_order(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    currentLevel.push(root);

    bool leftToRight = true;
    while(!currentLevel.empty())
    {
        Node* temp = currentLevel.top();
        currentLevel.pop();

        if(temp != NULL)
        {
            cout << temp->value << " ";

            if(leftToRight)
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
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    cout<<"ZigZag Order traversal of binary tree is\n";

    zigzag_order(root);

    return 0;
}
