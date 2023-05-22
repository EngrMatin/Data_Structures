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

void verticalOrder(treeNode* root, int D, map<int,vector<int>> &M);

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

        if(left>n-1 || right>n-1)
        {
            cout << "Invalid Index" << endl;
            break;
        }

        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if(right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    map<int,vector<int>> M;
    verticalOrder(allNodes[0], 0, M);

    for(auto i: M)
    {
        cout<<i.first<<" : ";
        for(int j=0; j<(i.second).size(); j++)
        {
            cout<<(i.second)[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

void verticalOrder(treeNode* root, int D, map<int,vector<int>> &M)
{
    if(root==NULL)
    {
        return;
    }

    M[D].push_back(root->data);
    verticalOrder(root->leftChild, D-1, M);
    verticalOrder(root->rightChild, D+1, M);
}

/*
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

           0
          / \
         /   \
        1     2
       / \   / \
      3  4  5   6
           / \
          7   8
*/
