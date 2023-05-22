#include<bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void inOrderTraversal(treeNode *root, string &chk);
treeNode* insertIntoBST(treeNode* root, int value);
void zigzagTraversal(treeNode* root);

int main()
{
    int n;
    cin>>n;

    treeNode *root = NULL;
    int value;
    for(int i=0; i<n; i++)
    {
        cin>>value;
        root = insertIntoBST(root, value);
    }

    string inOrderResult = "";
    inOrderTraversal(root, inOrderResult);
    cout<<"Inorder Traversal: "<<inOrderResult<<endl;

    zigzagTraversal(root);

    return 0;
}

void inOrderTraversal(treeNode *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    inOrderTraversal(root->leftChild, chk);
    chk += (to_string(root->data) + " ");
    inOrderTraversal(root->rightChild, chk);
}

treeNode* insertIntoBST(treeNode* root, int value)
{
    treeNode* newNode = new treeNode (value);

    if(root==NULL)
    {
        root = newNode;
        return root;
    }

    if(value < root->data)
    {
        root->leftChild = insertIntoBST(root->leftChild, value);
    }
    else if(value > root->data)
    {
        root->rightChild = insertIntoBST(root->rightChild, value);
    }

    return root;
}

void zigzagTraversal(treeNode* root)
{
    stack<treeNode*> currentLevel;
    stack<treeNode*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty())
    {
        treeNode* temp = currentLevel.top();
        currentLevel.pop();

        cout << temp->data << " ";

        if(leftToRight)
        {
            if(temp->leftChild != NULL)
            {
                nextLevel.push(temp->leftChild);
            }

            if(temp->rightChild != NULL)
            {
                nextLevel.push(temp->rightChild);
            }
        }
        else
        {
            if(temp->rightChild != NULL)
            {
                nextLevel.push(temp->rightChild);
            }

            if(temp->leftChild != NULL)
            {
                nextLevel.push(temp->leftChild);
            }
        }

        if(currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

/*

9
11 5 9 43 34 1 2 7 21

11
15 26 11 8 12 20 30 35 14 9 6

*/
