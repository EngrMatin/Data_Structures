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

void printTree(treeNode *root, int level);
void spacePrint(int level);
void inOrderTraversal(treeNode *root, string &chk);
void preOrderTraversal(treeNode *root, string &chk);
void postOrderTraversal(treeNode *root, string &chk);
int levelOrderTraversal(treeNode *root, string &chk, int k);
void boundaryTreeTraversal(treeNode *root);
void printLeaves(treeNode *root);
void printLeftNonLeaves(treeNode *root);
void printRightNonLeaves(treeNode *root);
treeNode* insertIntoBST(treeNode* root, int value);

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
//
//    string preOrderResult = "";
//    preOrderTraversal(allNodes[0], preOrderResult);
//    cout<<"Preorder Traversal: "<<preOrderResult<<endl;
//
//    string postOrderResult = "";
//    postOrderTraversal(allNodes[0], postOrderResult);
//    cout<<"Postorder Traversal: "<<postOrderResult<<endl;
//
//    string levelOrderResult = "";
//    //levelOrderTraversal(allNodes[0], levelOrderResult);
//    //cout<<"Level Order Traversal: "<<levelOrderResult<<endl;
//
//    int maxValueAtKLevel;
//    maxValueAtKLevel = levelOrderTraversal(allNodes[0], levelOrderResult, 2);
//    cout<<"maxValueAtKLevel: "<<maxValueAtKLevel<<endl;

    //boundaryTreeTraversal(allNodes[0]);

    return 0;
}

void printTree(treeNode *root, int level)
{
    if (root==NULL)
    {
        return;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data <<endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if(root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level+1);
    }

    if(root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level+1);
    }

}

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout <<"   ";
    }
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

void preOrderTraversal(treeNode *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    chk += (to_string(root->data) + " ");
    preOrderTraversal(root->leftChild, chk);
    preOrderTraversal(root->rightChild, chk);
}

void postOrderTraversal(treeNode *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    postOrderTraversal(root->leftChild, chk);
    postOrderTraversal(root->rightChild, chk);
    chk += (to_string(root->data) + " ");
}

int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int level = 0, max = -9999;
    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    cout<<"Level Order Traversal: ";
    while(!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();

        if(chkNode != NULL)
        {
            if(level == k)
            {
                if(max < chkNode->data)
                {
                    max = chkNode->data;
                }
            }

            cout<<chkNode->data<<" ";
            chk += (to_string(root->data) + " ");

            if(chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }

            if(chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    cout<<endl;

    return max;
}

void boundaryTreeTraversal(treeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";

    //LB Non-leaves
    printLeftNonLeaves(root->leftChild);
    //LB leaves
    printLeaves(root->leftChild);
    //RB leaves
    printLeaves(root->rightChild);
    //RB non-leaves;
    printRightNonLeaves(root->rightChild);
}

void printLeaves(treeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout<<root->data<<" ";
        return;
    }

    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->leftChild != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->rightChild != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
    else if(root->leftChild != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }

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

/*

9
11 5 9 43 34 1 2 7 21

*/
