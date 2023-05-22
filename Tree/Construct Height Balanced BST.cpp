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
Node* constructHeightBalancedBST(int l, int r, int array[]);  //input must be sorted

int main()
{
    int n;
    cin>>n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin>>array[i];           //input must be sorted
    }

    Node *root = NULL;
    root = constructHeightBalancedBST(0, n-1, array);

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

Node* constructHeightBalancedBST(int l, int r, int array[])       //same technique as binary searching
{                                                                 //input must be sorted
    if(l > r)
    {
        return NULL;
    }

    int mid = l+(r-l)/2;                     // same as (l+r)/2
    Node* newNode = new Node(array[mid]);
    newNode->left = constructHeightBalancedBST(l, mid-1, array);
    newNode->right = constructHeightBalancedBST(mid+1, r, array);

    return newNode;
}

/*

9
11 5 9 43 34 1 2 7 21

*/

