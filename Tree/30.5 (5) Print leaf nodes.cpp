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

int main()
{
    int n;
    cin>>n;

    treeNode *allNodes[n];
    for(int i=0; i<n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for(int i=0; i<n; i++)
    {
        int value, left, right;
        cin>>value>>left>>right;

        allNodes[i]->data = value;

//        if(left>n-1 || right>n-1)
//        {
//            cout << "Invalid Index" << endl;
//            break;
//        }

        if (left != -1)
        {
            //allNodes[i]->leftChild = allNodes[left];
            allNodes[i]->leftChild = new treeNode(left);
        }

        if(right != -1)
        {
            //allNodes[i]->rightChild = allNodes[right];
            allNodes[i]->rightChild = new treeNode(right);
        }
        printTree(allNodes[0], 0);
    }

    printTree(allNodes[0], 0);
//
//    string inOrderResult = "";
//    inOrderTraversal(allNodes[0], inOrderResult);
//    cout<<"Inorder Traversal: "<<inOrderResult<<endl;
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
    printLeaves(allNodes[0]);

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
    chk += to_string(root->data);
    inOrderTraversal(root->rightChild, chk);
}

void preOrderTraversal(treeNode *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    chk += to_string(root->data);
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
    chk += to_string(root->data);
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
            chk += to_string(chkNode->data);

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

/*

9
10 11 12
11 13 14
12 15 16
13 -1 -1
14 -1 -1
15 17 18
16 -1 -1
17 -1 -1
18 -1 -1

Root: 10
Left:
    root: 11
    Left: 13
    Right: 14
Right:
    root: 12
    Left:
        root: 15
        Left: 17
        Right: 18
    Right: 16


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root: 0
Left:
    root: 1
    Left: 3
    Right: 4
Right:
    root: 2
    Left:
        root: 5
        Left: 7
        Right: 8
    Right: 6

*/
