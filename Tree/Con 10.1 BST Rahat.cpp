#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(Node *root, string &chk);
void levelOrderTraversal(Node *root);
void insertIntoBST(Node* &root, int value);

int main()
{
    int n;
    cin>>n;

    Node *root = NULL;
    int value;
    for(int i=0; i<n; i++)
    {
        cin>>value;
        insertIntoBST(root, value);
    }

    levelOrderTraversal(root);

    string inOrderResult = "";
    inOrderTraversal(root, inOrderResult);
    cout<<"Inorder Traversal: "<<inOrderResult<<endl;


    return 0;
}

void inOrderTraversal(Node *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left, chk);
    chk += (to_string(root->val) + " ");
    inOrderTraversal(root->right, chk);
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);

    cout<<"Level Order Traversal: ";
    while(!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        cout<<parent->val<<" ";

        if(parent->left != NULL)
        {
            q.push(parent->left);
        }

        if(parent->right != NULL)
        {
            q.push(parent->right);
        }
    }
    cout<<endl;
}

void insertIntoBST(Node* &root, int value)
{
    if(root==NULL)
    {
        root = new Node(value);
        return;
    }

    if(value < root->val)
    {
        insertIntoBST(root->left, value);
    }
    else
    {
        insertIntoBST(root->right, value);
    }
}

